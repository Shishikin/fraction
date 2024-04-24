// fraction.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void  SwapIfALessB(int& a, int& b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
}

int Nod(int a, int b)
{
    SwapIfALessB(a, b);
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        Nod(b, a % b);
    }
}

class Fraction
{
private:
    int numerator = 1;
    int denominator = 1;

protected:
    void ShortenFraction()
    {
        int nod = Nod(std::abs(numerator), std::abs(denominator));
        numerator = numerator / nod;
        denominator = denominator / nod;
    }

public:

    Fraction(int n_, int d_): numerator(n_), denominator(d_) 
    {
        ShortenFraction();
    }
    Fraction() {}

    Fraction operator +(const Fraction& other)
    {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.ShortenFraction();
        return result;
    }

    Fraction operator -(const Fraction& other)
    {
        Fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.ShortenFraction();
        return result;
    }

    Fraction operator *(const Fraction& other)
    {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        result.ShortenFraction();
        return result;
    }

    Fraction operator /(const Fraction& other)
    {
        Fraction result;
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        result.ShortenFraction();
        return result;
    }

    friend std::ostream& operator << (std::ostream& out, const Fraction& fraction)
    {
        out << fraction.numerator << '/' << fraction.denominator;
        return out;
    }
};

int main()
{

    Fraction test1 = Fraction(3, 7);
    Fraction test2 = Fraction(5, 3);
    Fraction summa = test1 + test2;
    std::cout << summa << '\n';
    summa = test1 - test2;
    std::cout << summa << '\n';
    summa = test1 * test2;
    std::cout << summa << '\n';
    summa = test1 / test2;
    std::cout << summa << '\n';
    std::cout << "Hello World!\n";
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
