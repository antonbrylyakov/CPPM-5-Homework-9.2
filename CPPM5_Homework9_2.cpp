#include <iostream>
#include "Fraction.h"
#include <stdexcept>

Fraction getFractionFromConsole(int num)
{
    int n, d;
    std::cout << "Введите числитель дроби " << num << " :";
    std::cin >> n;
    std::cout << "Введите знаменатель дроби " << num << " :";
    std::cin >> d;

    return Fraction(n, d);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        Fraction f1 = getFractionFromConsole(1);
        Fraction f2 = getFractionFromConsole(2);

        std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << std::endl;
        std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << std::endl;
        std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << std::endl;
        std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << std::endl;

        // сохраняем для вывода, т.к. инкремент выполняется раньше оператора вывода
        Fraction f1Copy = f1;
        std::cout << "++" << f1Copy << " * " << f2 << " = " << (++f1 * f2) << std::endl;
        std::cout << "значение дроби 1 = " << f1 << std::endl;
        f1Copy = f1;
        std::cout << f1Copy << "-- * " << f2 << " = " << (f1-- * f2) << std::endl;
        std::cout << "значение дроби 1 = " << f1 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Ошибка! " << e.what() << std::endl;
    }

}
