#pragma once

#include <istream>
#include <map>
#include <ostream>
#include <string>

class Currency
{
private:
    std::string name;
    std::string country;
    double rate; //курс
    int dollarRatio; //відношення до долара: скільки одиниць валюти за 1 долар (ціле)
    std::map<int, int> banknotes; //наявні банкноти: номінал і кількість

public:
	Currency(); //конструкор за замовчуванням
	Currency(const std::string& name, const std::string& country, double rate, int dollarRatio); //конструктор з параметрами
	Currency(const Currency& other); //конструктор копіювання
	Currency(Currency&& other) noexcept; //конструктор переміщення
	~Currency(); //деструктор
	Currency& operator=(const Currency& other); //оператор присвоєння копіюванням
	Currency& operator=(Currency&& other) noexcept; //оператор присвоєння переміщенням

    //геттери
    const std::string& GetName() const { return name; }
    const std::string& GetCountry() const { return country; }
    double GetRate() const { return rate; }
    int GetDollarRatio() const { return dollarRatio; }
    const std::map<int, int>& GetBanknotes() const { return banknotes; }

    //додає/вилучає банкноти вказаного номіналу
    void AddBanknotes(int denomination, int quantity);
    void RemoveBanknotes(int denomination, int quantity);

    //сума наявних банкнот, переведена в долари за курсом
    double BanknotesInDollars() const;

    //текст для відображення банкнот, наприклад: "5x10, 20x3"
    std::string BanknotesToString() const;

    //запис/зчитування валюти у потік (файл): один рядок на валюту
    friend std::ostream& operator<<(std::ostream& out, const Currency& currency);
    friend std::istream& operator>>(std::istream& in, Currency& currency);
};