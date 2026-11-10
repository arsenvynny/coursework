#include "Currency.h"
#include "CurrencyException.h"

#include <climits>
#include <sstream>
#include <vector>

//повідомлення про помилку у файлі
static const char* const BAD_FILE_TEXT = "Файл пошкоджений або містить некоректний запис про валюту";

//конструктор за замовчуванням
Currency::Currency() : name(), country(), rate(0), dollarRatio(0), banknotes() {}

//конструктор з параметрами
Currency::Currency(const std::string& name, const std::string& country, double rate, int dollarRatio)
    : name(name), country(country), rate(rate), dollarRatio(dollarRatio), banknotes()
{
    if (name.empty())
        throw CurrencyException("Назва валюти не може бути порожньою");
    if (country.empty())
        throw CurrencyException("Країна не може бути порожньою");
    if (name.find(';') != std::string::npos || country.find(';') != std::string::npos)
        throw CurrencyException("Назва і країна не можуть містити символ «;»");
    if (!(rate > 0) || rate > 1e12)
        throw CurrencyException("Курс має бути додатним числом (не більше 1e12)");
    if (dollarRatio < 1 || dollarRatio > 1000000)
        throw CurrencyException("Відношення до долара має бути цілим числом від 1 до 1000000");
}

//конструктор копіювання
Currency::Currency(const Currency& other)
    : name(other.name), country(other.country), rate(other.rate),
      dollarRatio(other.dollarRatio), banknotes(other.banknotes)
{}

//конструктор переміщення: забирає дані з other
Currency::Currency(Currency&& other) noexcept
    : name(std::move(other.name)), country(std::move(other.country)), rate(other.rate),
    dollarRatio(other.dollarRatio), banknotes(std::move(other.banknotes))
{}

//деструктор
Currency::~Currency() {}

//оператор присвоєння копіюванням
Currency& Currency::operator=(const Currency& other)
{
    if (this != &other)
    {
        name = other.name;
        country = other.country;
        rate = other.rate;
        dollarRatio = other.dollarRatio;
        banknotes = other.banknotes;
    }
    return *this;
}

//оператор переміщення
Currency& Currency::operator=(Currency&& other) noexcept
{
    if (this != &other)
    {
        name = std::move(other.name);
        country = std::move(other.country);
        rate = other.rate;
        dollarRatio = other.dollarRatio;
        banknotes = std::move(other.banknotes);
    }
    return *this;
}

//додавання банкнот: якщо номінал уже є - збільшуємо кількість
void Currency::AddBanknotes(int denomination, int quantity)
{
    if (denomination <= 0 || quantity <= 0)
        throw CurrencyException("Номінал і кількість банкнот мають бути додатними цілими числами");

    int& current = banknotes[denomination]; //якщо номіналу немає, буде 0
    if (current > INT_MAX - quantity)
        throw CurrencyException("Занадто велика кількість банкнот");
    current += quantity;
}

//вилучення банкнот
void Currency::RemoveBanknotes(int denomination, int quantity)
{
    if (denomination <= 0 || quantity <= 0)
        throw CurrencyException("Номінал і кількість банкнот мають бути додатними цілими числами");

    std::map<int, int>::iterator it = banknotes.find(denomination);
    if (it == banknotes.end())
        throw CurrencyException("Банкнот такого номіналу немає");
    if (it->second < quantity)
        throw CurrencyException("Недостатньо банкнот: наявно лише " + std::to_string(it->second));

    it->second -= quantity;
    if (it->second == 0)
        banknotes.erase(it); //номінал без банкнот не зберігаємо
}

//сума банкнот у доларах = (сума номінал * кількість) * курс
double Currency::BanknotesInDollars() const
{
    double sum = 0;
    for (const auto& note : banknotes)
        sum += static_cast<double>(note.first) * note.second;
    return sum * rate;
}

//текстове подання банкнот
std::string Currency::BanknotesToString() const
{
    if (banknotes.empty())
        return "-";

    std::string text;
    for (const auto& note : banknotes)
    {
        if (!text.empty())
            text += ", ";
        text += std::to_string(note.first) + "x" + std::to_string(note.second);
    }
    return text;
}

//запис у потік, формат рядка: назва;країна;курс;відношення;номінал:кількість номінал:кількість
std::ostream& operator<<(std::ostream& out, const Currency& currency)
{
    out << currency.name << ';' << currency.country << ';' << currency.rate << ';'
        << currency.dollarRatio << ';';

    bool first = true;
    for (const auto& note : currency.banknotes)
    {
        if (!first)
            out << ' ';
        first = false;
        out << note.first << ':' << note.second;
    }
    out << '\n';
    return out;
}

//зчитування з потоку
std::istream& operator>>(std::istream& in, Currency& currency)
{
    //читаю рядок, порожні рядки пропускаю
    std::string line;
    do
    {
        if (!std::getline(in, line))
            return in; //кінець файлу
    } while (line.find_first_not_of(" \t\r") == std::string::npos);

    //ділення рядок на поля за символом ';'
    std::vector<std::string> fields;
    std::stringstream parts(line);
    std::string field;
    while (std::getline(parts, field, ';'))
        fields.push_back(field);

    if (fields.size() < 4 || fields.size() > 5)
        throw CurrencyException(BAD_FILE_TEXT);

    double rate = 0;
    int ratio = 0;
    try
    {
        rate = std::stod(fields[2]);
        ratio = std::stoi(fields[3]);
    }
    catch (const std::exception&)
    {
        throw CurrencyException(BAD_FILE_TEXT);
    }

    Currency parsed(fields[0], fields[1], rate, ratio); //перевірка значень

    //п'яте поле (банкноти) не обов'язкове: пари "номінал:кількість" через пробіл
    if (fields.size() == 5)
    {
        std::stringstream notes(fields[4]);
        std::string token;
        while (notes >> token)
        {
            std::string::size_type colon = token.find(':');
            if (colon == std::string::npos)
                throw CurrencyException(BAD_FILE_TEXT);
            try
            {
                int denomination = std::stoi(token.substr(0, colon));
                int quantity = std::stoi(token.substr(colon + 1));
                parsed.AddBanknotes(denomination, quantity);
            }
            catch (const std::invalid_argument&)
            {
                throw CurrencyException(BAD_FILE_TEXT);
            }
            catch (const std::out_of_range&)
            {
                throw CurrencyException(BAD_FILE_TEXT);
            }
        }
    }

    currency = std::move(parsed); //використовується оператор переміщення
    return in;
}