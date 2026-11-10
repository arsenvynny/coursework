#pragma once

#include <string>

class CurrencyException
{
private:
    std::string message; // текст повідомлення

public:
    // Конструктор з параметрами
    explicit CurrencyException(const std::string& text) : message(text) {}

    // Повертає текст повідомлення
    const std::string& GetText() const { return message; }
};