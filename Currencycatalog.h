#pragma once

#include <map>
#include <string>
#include <vector>

#include "Currency.h"

class CurrencyCatalog
{
private:
    std::vector<Currency> currencies; //усі валюти

    //індекс валюти за назвою або -1, якщо не знайдено
    int FindIndex(const std::string& name) const;

    //індекс валюти за назвою; якщо не знайдено - виняток
    int RequireIndex(const std::string& name) const;

public:
    //конструктор за замовчуванням
    CurrencyCatalog();

    //деструктор
    ~CurrencyCatalog();

    //доступ до списку
    const std::vector<Currency>& GetAll() const { return currencies; }
    int Count() const { return static_cast<int>(currencies.size()); }

    //додавання/видалення валют
    void AddCurrency(const Currency& currency);
    void RemoveCurrency(const std::string& name);
    void Clear();

    //пошук валют за назвою
    std::vector<Currency> SearchByName(const std::string& part) const;

    //валюти, що мають курс від from до to
    std::vector<Currency> FilterByRate(double from, double to) const;

    //додавання/вилучення банкнот вибраної валюти
    void AddBanknotes(const std::string& name, int denomination, int quantity);
    void RemoveBanknotes(const std::string& name, int denomination, int quantity);

    //сортування за відношенням до долара методом підрахунку (за зростанням)
    void SortByDollarRatio();

    //валюти, згруповані за країнами (за алфавітом)
    std::map<std::string, std::vector<Currency>> GroupByCountry() const;

    //сума наявних банкнот у доларах для кожної країни
    std::map<std::string, double> TotalsInDollarsByCountry() const;

    //текстові звіти
    std::string BuildCountryReport() const;
    std::string BuildDollarReport() const;

    //робота з текстовим файлом (один рядок = одна валюта)
    void LoadFromFile(const std::string& path);
    void SaveToFile(const std::string& path) const;
};