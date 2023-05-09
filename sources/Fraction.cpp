#include "Fraction.hpp"
#include <cmath>
#include <iomanip>

namespace ariel
{
    Fraction::Fraction() {}
    Fraction::Fraction(int Numerator, int Denumerator)
    {
        if (Denumerator == 0)
            std::__throw_runtime_error("Can't divide by 0");
        else
        {
            int gcd = this->gcd(Numerator, Denumerator);
            Numerator /= gcd;
            Denumerator /= gcd;
            numerator = Numerator;
            denominator = Denumerator;
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

    int Fraction::getNumerator()const
    {
        return this->numerator;
    }

    int Fraction::getDenominator()const
    {
        return this->denominator;
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
            std::__throw_runtime_error("Can't divide by 0");
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
        std::cout << other.getNumerator() << "/" << other.getDenominator() << endl;
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
            std::__throw_runtime_error("Can't divide by 0");
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
        std::cout << num.getNumerator() << "/" << num.getDenominator() << endl;

        return num.operator*(other);
    }
    Fraction operator/(double number, const Fraction &other)
    {
        if (other.denominator == 0 && other.numerator == 0)
            std::__throw_runtime_error("Can't divide by 0");
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
        double a = (double)this->numerator / this->denominator;
        double b = (double)other.numerator / other.denominator;
        return a == b;
    }
    bool Fraction::operator<(const Fraction &other) const
    {
        double a = (double)this->numerator / this->denominator;
        double b = (double)other.numerator / other.denominator;
        return a < b;
    }
    bool Fraction::operator>(const Fraction &other) const
    {
        double a = (double)this->numerator / this->denominator;
        double b = (double)other.numerator / other.denominator;
        return a > b;
    }
    bool Fraction::operator<=(const Fraction &other) const
    {
        return (operator==(other) || operator<(other));
    }
    bool Fraction::operator>=(const Fraction &other) const
    {
        return (operator==(other) || operator>(other));
    }

    // Fraction VS Number
    bool Fraction::operator==(double number) const
    {
        Fraction num = Fraction(number);
        return operator==(num);
    }
    bool Fraction::operator<(double number) const
    {
        Fraction num = Fraction(number);
        return operator<(num);
    }
    bool Fraction::operator>(double number) const
    {
        Fraction num = Fraction(number);
        return operator>(num);
    }
    bool Fraction::operator<=(double number) const
    {
        Fraction num = Fraction(number);
        return operator<=(num);
    }
    bool Fraction::operator>=(double number) const
    {
        Fraction num = Fraction(number);
        return operator>=(num);
    }

    // Number VS Fraction
    bool operator==(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        double a = (double)other.numerator / other.denominator;
        double b = (double)num.numerator / num.denominator;
        return a == b;
    }
    bool operator<(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        double a = (double)other.numerator / other.denominator;
        double b = (double)num.numerator / num.denominator;
        return b < a;
    }
    bool operator>(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        double a = (double)other.numerator / other.denominator;
        double b = (double)num.numerator / num.denominator;
        return b > a;
    }
    bool operator<=(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        double a = (double)other.numerator / other.denominator;
        double b = (double)num.numerator / num.denominator;
        return b <= a;
    }
    bool operator>=(double number, const Fraction &other)
    {
        Fraction num = Fraction(number);
        double a = (double)other.numerator / other.denominator;
        double b = (double)num.numerator / num.denominator;
        return b >= a;
    }

    // postfix increment
    Fraction operator++(Fraction &frac, int)
    {
        Fraction cpy(frac.getNumerator(), frac.getDenominator());
        ++frac;
        return cpy;
    }
    Fraction operator--(Fraction &frac, int)
    // postfix decrement
    {
        Fraction cpy(frac.getNumerator(), frac.getDenominator());
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
    ostream &operator<<(std::ostream &outStream, const Fraction &fraction)
    {
        outStream << fraction.getNumerator() << "/" << fraction.getDenominator();
        return outStream;
    }
    istream &operator>>(istream &inStream, Fraction &fraction)
    {
           if (inStream.peek() == EOF)//first argument
        {
            throw std::runtime_error("The input is empty");
        }
        if (!(inStream >> fraction.numerator))//save the 1'st argument as a numerator
        {
            throw std::runtime_error("Not valid input for numerator");
        }
        if (inStream.peek() == EOF)//second argument
        {
            throw std::runtime_error("Not valid input, only 1 argument was entered");
        }
        if (!(inStream >> fraction.denominator))//save the 2'nd argument as a denumerator
        {
            throw std::runtime_error("Not valid input for denumerator");
        }
        if (fraction.denominator == 0)//check if the denomerator is 0
        {
            throw std::runtime_error("Can't divide by 0");
        }
        else if (fraction.denominator < 0) //helnde with possetive denomerator
        {
            fraction.numerator *= -1;
            fraction.denominator *= -1;
        }

        return inStream;
        
    }

    int Fraction::gcd(int numerator, int denumerator) const
    {
        while (denumerator != 0)
        {
            int t = denumerator;
            denumerator = numerator % denumerator;
            numerator = t;
        }
        return numerator;
    }

    int Fraction::lcm(int numerator, int denumerator) const
    {
        return (numerator * denumerator) / gcd(numerator, denumerator);
    }
}