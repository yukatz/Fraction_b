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
        double rounded = (n * 1000) / 1000;
        int numOfDig;
        int j = 1000;
        for (int i = 0; i < 3; i++)
        {
            int temp = static_cast<int>(floor((rounded * j) - floor(rounded * j / 10) * 10));
            if (temp != 0)
                numOfDig++;
            j / 10;
        }
        double intpart;
        int intpart = static_cast<int>(rounded);
        double fractpart = modf(rounded, &intpart);
        denominator = pow(10, numOfDig);
        numerator = intpart * denominator + fractpart;
    }

    void Fraction::fractReduct()
    {
        int gcd = this->gcd(this->numerator, this->denominator);
        this->numerator/= gcd;
        this->denominator/= gcd;
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

    string Fraction::fractToString()
    {
        string res = this->numerator + "/" + this->denominator;
        return res;
    }

    Fraction Fraction::operator+(const Fraction &other) const
    {
        int commonDenominator = lcm(denominator, other.denominator);
        int newNumerator = numerator * (commonDenominator / denominator) + other.numerator * (commonDenominator / other.denominator);
        return Fraction(newNumerator, commonDenominator);
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        int commonDenominator = lcm(denominator, other.denominator);
        int newNumerator = numerator * (commonDenominator / denominator) - other.numerator * (commonDenominator / other.denominator);
        return Fraction(newNumerator, commonDenominator);
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (other.denominator == 0 && other.numerator == 0)
            __throw_invalid_argument("Can't divide by 0");
        else
        {
            int newNumerator = numerator * other.denominator;
            int newDenominator = denominator * other.numerator;
            return Fraction(newNumerator, newDenominator);
        }
    }

    // Fraction VS Number
    Fraction Fraction::operator+(double number) const
    {
        Fraction other = Fraction(number);
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
        
        if((this->numerator == other.numerator)&&(this->denominator == other.denominator)){
        return true;
        }else 
        return false;

    }
    bool Fraction::operator<(const Fraction &other) const
    {
        return true;
    }
    bool Fraction::operator>(const Fraction &other) const
    {
        return true;
    }
    bool Fraction::operator<=(const Fraction &other) const
    {
        return true;
    }
    bool Fraction::operator>=(const Fraction &other) const
    {
        return true;
    }

    // Fraction VS Number
    bool Fraction::operator==(double number) const
    {
        return true;
    }
    bool Fraction::operator<(double number) const
    {
        return true;
    }
    bool Fraction::operator>(double number) const
    {
        return true;
    }
    bool Fraction::operator<=(double number) const
    {
        return true;
    }
    bool Fraction::operator>=(double number) const
    {
        return true;
    }

    // Number VS Fraction
    bool operator==(double number, const Fraction &other)
    {
        return true;
    }
    bool operator<(double number, const Fraction &other)
    {
        return true;
    }
    bool operator>(double number, const Fraction &other)
    {
        return true;
    }
    bool operator<=(double number, const Fraction &other)
    {
        return true;
    }
    bool operator>=(double number, const Fraction &other)
    {
        return true;
    }

    // Fraction ++/--
    Fraction &Fraction::operator++(int number)
    {
        return *this;
    }
    Fraction &Fraction::operator--(int number)
    {
        return *this;
    }

    //++/--Fraction
    Fraction Fraction::operator--()
    {
        return Fraction();
    }
    Fraction Fraction::operator++()
    {
        return Fraction();
    }

    // Consule In & Consule Out
    ostream &operator<<(ostream &os, const Fraction &f)
    {
        return os;
    }
    istream &operator>>(istream &is, Fraction &f)
    {
        is >> f.numerator >> f.denominator;
        return is;
    }

    int Fraction::gcd(int a, int b) const
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int Fraction::lcm(int a, int b) const
    {
        return (a * b) / gcd(a, b);
    }
}