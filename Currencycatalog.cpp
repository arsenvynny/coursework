#include "CurrencyCatalog.h"
#include "CurrencyException.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <sstream>

//конструктор за замовчуванням
CurrencyCatalog::CurrencyCatalog() : currencies() {}

//деструктор
CurrencyCatalog::~CurrencyCatalog() {}

int CurrencyCatalog::FindIndex(const std::string& name) const
{
    auto it = std::find_if(currencies.begin(), currencies.end(),
        [&name](const Currency& c) { return c.GetName() == name; });
    if (it == currencies.end())
        return -1;
    return static_cast<int>(it - currencies.begin());
}

int CurrencyCatalog::RequireIndex(const std::string& name) const
{
    int index = FindIndex(name);
    if (index == -1)
        throw CurrencyException("Валюту не знайдено");
    return index;
}

void CurrencyCatalog::AddCurrency(const Currency& currency)
{
    if (FindIndex(currency.GetName()) != -1)
        throw CurrencyException("Валюта з такою назвою вже існує");
    currencies.push_back(currency);
}

void CurrencyCatalog::RemoveCurrency(const std::string& name)
{
    int index = RequireIndex(name);
    currencies.erase(currencies.begin() + index);
}

void CurrencyCatalog::Clear()
{    currencies.clear();}

//пошук: усі валюти, назва яких містить введений текст (регістр має значення)
std::vector<Currency> CurrencyCatalog::SearchByName(const std::string& part) const
{
    if (part.empty())
        throw CurrencyException("Введіть назву валюти для пошуку");

    std::vector<Currency> result;
    std::copy_if(currencies.begin(), currencies.end(), std::back_inserter(result),
        [&part](const Currency& c) { return c.GetName().find(part) != std::string::npos; });

    if (result.empty())
        throw CurrencyException("Валюту з такою назвою не знайдено");
    return result;
}

//фільтр за курсом: from <= курс <= to
std::vector<Currency> CurrencyCatalog::FilterByRate(double from, double to) const
{
    if (from > to)
        throw CurrencyException("Нижня межа курсу не може бути більшою за верхню");

    std::vector<Currency> result;
    std::copy_if(currencies.begin(), currencies.end(), std::back_inserter(result),
        [from, to](const Currency& c) { return c.GetRate() >= from && c.GetRate() <= to; });
    return result;
}

void CurrencyCatalog::AddBanknotes(const std::string& name, int denomination, int quantity)
{    currencies[RequireIndex(name)].AddBanknotes(denomination, quantity);}

void CurrencyCatalog::RemoveBanknotes(const std::string& name, int denomination, int quantity)
{    currencies[RequireIndex(name)].RemoveBanknotes(denomination, quantity);}

//сортування підрахунком за відношенням до долара (стабільне, за зростанням)
void CurrencyCatalog::SortByDollarRatio()
{
    if (currencies.empty())
        throw CurrencyException("Список валют порожній");

    //1.найбільший ключ - розмір масиву лічильників
    auto biggest = std::max_element(currencies.begin(), currencies.end(),
        [](const Currency& a, const Currency& b) { return a.GetDollarRatio() < b.GetDollarRatio(); });
    int maxKey = biggest->GetDollarRatio();

    //2.скільки разів зустрічається кожен ключ
    std::vector<int> count(maxKey + 1, 0);
    for (const auto& c : currencies)
        ++count[c.GetDollarRatio()];

    //3.накопичені суми показують кінцеву позицію кожного ключа
    for (int i = 1; i <= maxKey; ++i)
        count[i] += count[i - 1];

    //4.елементи з кінця (так сортування лишається стабільним)
    std::vector<Currency> result(currencies.size());
    for (int i = static_cast<int>(currencies.size()) - 1; i >= 0; --i)
    {
        int key = currencies[i].GetDollarRatio();
        result[--count[key]] = std::move(currencies[i]); // оператор переміщення
    }
    currencies = std::move(result);
}

//групування за країнами: map сам тримає ключі (країни) відсортованими
std::map<std::string, std::vector<Currency>> CurrencyCatalog::GroupByCountry() const
{
    std::map<std::string, std::vector<Currency>> groups;
    for (const auto& c : currencies)
        groups[c.GetCountry()].push_back(c);
    return groups;
}

//сума в доларах для кожної країни
std::map<std::string, double> CurrencyCatalog::TotalsInDollarsByCountry() const
{
    if (currencies.empty())
        throw CurrencyException("Список валют порожній");

    std::map<std::string, double> totals;
    for (const auto& c : currencies)
        totals[c.GetCountry()] += c.BanknotesInDollars();
    return totals;
}

//звіт: країни за алфавітом, для кожної - валюти та наявні банкноти
std::string CurrencyCatalog::BuildCountryReport() const
{
    if (currencies.empty())
        throw CurrencyException("Список валют порожній");

    std::ostringstream out;
    for (const auto& group : GroupByCountry())
    {
        out << group.first << ":\r\n";
        for (const auto& c : group.second)
            out << "    " << c.GetName() << " - банкноти: " << c.BanknotesToString() << "\r\n";
    }
    return out.str();
}

//звіт: банкноти кожної валюти в доларах і загальна сума для країни
std::string CurrencyCatalog::BuildDollarReport() const
{
    if (currencies.empty())
        throw CurrencyException("Список валют порожній");

    std::ostringstream out;
    out << std::fixed << std::setprecision(2);
    for (const auto& group : GroupByCountry())
    {
        double total = 0;
        out << group.first << ":\r\n";
        for (const auto& c : group.second)
        {
            double dollars = c.BanknotesInDollars();
            total += dollars;
            out << "    " << c.GetName() << ": " << dollars << " USD\r\n";
        }
    }
    return out.str();
}

//завантаження з файлу, спочатку у тимчасовий каталог
void CurrencyCatalog::LoadFromFile(const std::string& path)
{
    std::ifstream in(path);
    if (!in.is_open())
        throw CurrencyException("Не вдалося відкрити файл");

    CurrencyCatalog loaded;
    Currency currency;
    while (in >> currency)
        loaded.AddCurrency(currency);

    if (loaded.Count() == 0)
        throw CurrencyException("Файл не містить жодної валюти");

    currencies = std::move(loaded.currencies);
}

//збереження у файл
void CurrencyCatalog::SaveToFile(const std::string& path) const
{
    std::ofstream out(path);
    if (!out.is_open())
        throw CurrencyException("Не вдалося створити файл для запису");

    for (const auto& c : currencies)
        out << c;
}