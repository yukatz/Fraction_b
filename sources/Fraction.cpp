#include "Fraction.hpp"
#include <cmath>
#include <iomanip>

namespace ariel
{
    Fraction::Fraction() {}
    Fraction::Fraction(int n, int d)
    {
        if (d == 0)
            __throw_invalid_argument("Can't divide by 0");
        else
        {
            numerator = n;
            denominator = d;
        }
    }
    Fraction::Fraction(double n)
    {
        int num = n * 1000;
        int denum = 1000;
        this->numerator = num / (gcd(num, denum));
        this->denominator = denum / (gcd(num, denum));
    }

    void Fraction::fractReduct()
    {
        int gcd = this->gcd(this->numerator, this->denominator);
        this->numerator /= gcd;
        this->denominator /= gcd;
    }

    int Fraction::getNum()
    {
        return numerator;
    }

    int Fraction::getDenom()
    {
        return denominator;
    }

    void Fraction::setNum(int n)
    {
        numerator = n;
    }
    void Fraction::setDenom(int n)
    {
        denominator = n;
    }

    Fraction Fraction::operator+(const Fraction &other) const
    {
        int commonDenominator = lcm(denominator, other.denominator);
        int newNumerator = numerator * (commonDenominator / denominator) + other.numerator * (commonDenominator / other.denominator);
        Fraction a(newNumerator, commonDenominator);
        a.fractReduct();
        return a;
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        int commonDenominator = lcm(denominator, other.denominator);
        int newNumerator = numerator * (commonDenominator / denominator) - other.numerator * (commonDenominator / other.denominator);
        Fraction a(newNumerator, commonDenominator);
        a.fractReduct();
        return a;
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        Fraction a(newNumerator, newDenominator);
        a.fractReduct();
        return a;
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (other.denominator == 0 && other.numerator == 0)
            __throw_invalid_argument("Can't divide by 0");
        else
        {
            int newNumerator = numerator * other.denominator;
            int newDenominator = denominator * other.numerator;
            Fraction a(newNumerator, newDenominator);
            a.fractReduct();
            return a;
        }
    }

    // Fraction VS Number
    Fraction Fraction::operator+(double number) const
    {
        Fraction other = Fraction(number);
        std::cout << other.getNum() << "/" << other.getDenom() << endl;
        return this->operator+(other);
    }
    Fraction Fraction::operator-(double number) const
    {
        Fraction other = Fraction(number);
        return this->operator-(other);
    }

    Fraction Fraction::operator*(double number) const
    {
        Fraction other = Fraction(number);
        return this->operator*(other);
    }
    Fraction Fraction::operator/(double number) const
    {
        if (number == 0)
            __throw_invalid_argument("Can't divide by 0");
        else
        {
            Fraction other = Fraction(number);
            return this->operator/(other);
        }
    }

    // Number VS Fraction
    Fraction operator+(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        return num.operator+(other);
    }
    Fraction operator-(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        return num.operator-(other);
    }
    Fraction operator*(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        std::cout << num.getNum() << "/" << num.getDenom() << endl;

        return num.operator*(other);
    }
    Fraction operator/(double number, const Fraction &other)
    {
        if (other.denominator == 0 && other.numerator == 0)
            __throw_invalid_argument("Can't divide by 0");
        else
        {
            Fraction num = Fraction(number);
            return num.operator/(other);
        }
    }

    // Overloading comperators ==,<,>,<=,>=
    // Fraction VS Fraction
    bool Fraction::operator==(const Fraction &other) const
    {
        double a = this->numerator / this->denominator;
        double b = other.numerator / other.denominator;
        return a == b;
    }
    bool Fraction::operator<(const Fraction &other) const
    {
        double a = this->numerator / this->denominator;
        double b = other.numerator / other.denominator;
        return a > b;
    }
    bool Fraction::operator>(const Fraction &other) const
    {
        double a = this->numerator / this->denominator;
        double b = other.numerator / other.denominator;
        return a < b;
    }
    bool Fraction::operator<=(const Fraction &other) const
    {
        double a = this->numerator / this->denominator;
        double b = other.numerator / other.denominator;
        return a >= b;
    }
    bool Fraction::operator>=(const Fraction &other) const
    {
        double a = this->numerator / this->denominator;
        double b = other.numerator / other.denominator;
        return a <= b;
    }

    // Fraction VS Number
    bool Fraction::operator==(double number) const
    {
        Fraction num = Fraction(number);
        double a = this->numerator / this->denominator;
        double b = num.numerator / num.denominator;
        return a == b;
    }
    bool Fraction::operator<(double number) const
    {
        Fraction num = Fraction(number);
        double a = this->numerator / this->denominator;
        double b = num.numerator / num.denominator;
        return a < b;
    }
    bool Fraction::operator>(double number) const
    {
        Fraction num = Fraction(number);
        double a = this->numerator / this->denominator;
        double b = num.numerator / num.denominator;
        return a > b;
    }
    bool Fraction::operator<=(double number) const
    {
        Fraction num = Fraction(number);
        double a = this->numerator / this->denominator;
        double b = num.numerator / num.denominator;
        return a >= b;
    }
    bool Fraction::operator>=(double number) const
    {
        Fraction num = Fraction(number);
        double a = this->numerator / this->denominator;
        double b = num.numerator / num.denominator;
        return a <= b;
    }

    // Number VS Fraction
    bool operator==(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        double a = other.numerator / other.denominator;
        double b = num.numerator / num.denominator;
        return a == b;
    }
    bool operator<(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        double a = other.numerator / other.denominator;
        double b = num.numerator / num.denominator;
        return a < b;
    }
    bool operator>(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        double a = other.numerator / other.denominator;
        double b = num.numerator / num.denominator;
        return a > b;
    }
    bool operator<=(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        double a = other.numerator / other.denominator;
        double b = num.numerator / num.denominator;
        return a <= b;
    }
    bool operator>=(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        double a = other.numerator / other.denominator;
        double b = num.numerator / num.denominator;
        return a >= b;
    }

    // postfix increment
    Fraction operator++(Fraction &frac, int)
    {
        Fraction cpy(frac.getNum(), frac.getDenom());
        ++frac;
        return cpy;
    }
    Fraction operator--(Fraction &frac, int)
    // postfix decrement
    {
        Fraction cpy(frac.getNum(), frac.getDenom());
        --frac;
        return cpy;
    }

    // prefix increment
    Fraction const Fraction::operator++()
    {
        this->numerator += this->denominator;
        return *this;
    }
    // prefix decrement
    Fraction const Fraction::operator--()
    {
        this->numerator -= this->denominator;
        return *this;
    }

    // Consule In & Consule Out
    ostream &operator<<(std::ostream &os, const Fraction &f)
    {
        os << f.numerator << "/" << f.denominator << " ";
        return os;
    }
    istream &operator>>(istream &is, Fraction &f)
    {
        is >> f.numerator >> f.denominator;
        return is;
    }

    int Fraction::gcd(int a, int b) const
    {
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int Fraction::lcm(int a, int b) const
    {
        return (a * b) / gcd(a, b);
    }
}