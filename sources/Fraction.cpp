#include "Fraction.hpp"
#include <cmath>
#include <iomanip>
#include <limits>
namespace ariel
{
    Fraction::Fraction() {}
    Fraction::Fraction(int Numerator, int Denumerator)
    {

        if (Denumerator == 0)
        {
            std::__throw_invalid_argument("Can't divide by 0");
        }
        else
        {

            int gcd = this->gcd(Numerator, Denumerator);
            if (gcd < 0 && Numerator < 0 && Denumerator > 0)
            {
                gcd *= -1;
            }
            Numerator /= gcd;
            Denumerator /= gcd;
            numerator = Numerator;
            denominator = Denumerator;
        }
    }
    Fraction::Fraction(double number)
    {
        int num = number * 1000;
        int denum = 1000;
        this->numerator = num / (gcd(num, denum));
        this->denominator = denum / (gcd(num, denum));
    }
    void Fraction::fractReduct()
    {
        int gcd = this->gcd(this->numerator, this->denominator);
        int numerator = this->numerator / gcd;
        int denominator = this->denominator / gcd;
        if (denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int Fraction::getNumerator() const
    {
        return this->numerator;
    }

    int Fraction::getDenominator() const
    {
        return this->denominator;
    }

    void Fraction::setNum(int number)
    {
        numerator = number;
    }
    void Fraction::setDenom(int number)
    {
        denominator = number;
    }
    bool overFlow(const Fraction &fraction) // Checks the overflow
    {
        const long long maximum = std::numeric_limits<int>::max();
        const long long minimum = std::numeric_limits<int>::min();
        long long numerator = static_cast<long long>(fraction.numerator);
        long long denominator = static_cast<long long>(fraction.denominator);
        double result = static_cast<double>(numerator) / static_cast<double>(denominator);
        if ((result >= maximum) || (result <= minimum))
        {
            if (numerator >= maximum || numerator <= minimum || denominator >= maximum || denominator <= minimum)
            {
                return true;
            }
        }
        return false;
    }

    // Mathematic operators
    Fraction Fraction::operator+(const Fraction &other) const
    {
        if (overFlow(*this) || overFlow(other))
        {
            __throw_overflow_error("Overflow");
        }
        else
        {
            int commonDenominator = lcm(denominator, other.denominator);
            int newNumerator = numerator * (commonDenominator / denominator) + other.numerator * (commonDenominator / other.denominator);
            Fraction a(newNumerator, commonDenominator);
            a.fractReduct();

            return a;
        }
    }
    Fraction Fraction::operator-(const Fraction &other) const
    {
        const long long maximum = std::numeric_limits<int>::max();
        const long long minimum = std::numeric_limits<int>::min();
        if (overFlow(*this) || overFlow(other))
        {
            __throw_overflow_error("Overflow");
        }
        else
        {
            long long commonDenominator = lcm(denominator, other.denominator);
            long long newNumerator = numerator * (commonDenominator / denominator) - other.numerator * (commonDenominator / other.denominator);
            Fraction a(newNumerator, commonDenominator);
            if (newNumerator < minimum || newNumerator > maximum || commonDenominator < minimum || commonDenominator > maximum)
            {
                __throw_overflow_error("Overflow");
            }

            a.fractReduct();
            return a;
        }
    }
    Fraction Fraction::operator*(const Fraction &other) const
    {
        const long long maximum = std::numeric_limits<int>::max();
        const long long minimum = std::numeric_limits<int>::min();
        if (overFlow(*this) || overFlow(other))
        {
            __throw_overflow_error("Overflow");
        }
        else
        {
            long long newNumerator = static_cast<long long>(numerator) * static_cast<long long>(other.numerator);
            long long newDenominator = static_cast<long long>(denominator) * static_cast<long long>(other.denominator);
            Fraction a(newNumerator, newDenominator);

            if (newNumerator < minimum || newNumerator > maximum || newDenominator < minimum || newDenominator > maximum)
            {
                __throw_overflow_error("Overflow");
            }
            a.fractReduct();

            return a;
        }
    }
    Fraction Fraction::operator/(const Fraction &other) const
    {
        if (overFlow(*this) || overFlow(other))
        {
            __throw_overflow_error("Overflow");
        }
        else
        {
            if (other.denominator == 0 || other.numerator == 0)
                std::__throw_runtime_error("Can't divide by 0");
            else
            {
                Fraction fliped(other.denominator, other.numerator);
                return operator*(fliped);
            }
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
        if (inStream.peek() == EOF) // first argument
        {
            throw std::runtime_error("The input is empty");
        }
        if (!(inStream >> fraction.numerator)) // save the 1'st argument as a numerator
        {
            throw std::runtime_error("Not valid input for numerator");
        }
        if (inStream.peek() == EOF) // second argument
        {
            throw std::runtime_error("Not valid input, only 1 argument was entered");
        }
        if (!(inStream >> fraction.denominator)) // save the 2'nd argument as a denumerator
        {
            throw std::runtime_error("Not valid input for denumerator");
        }
        if (fraction.denominator == 0) // check if the denomerator is 0
        {
            throw std::runtime_error("Can't divide by 0");
        }
        if (fraction.denominator < 0) // helnde with possetive denomerator
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
        if (denominator < 0)//replace the minus between numerator  and denominator
        {
            numerator *= -1;
            denumerator *= -1;
        }
        return numerator;
    }

    int Fraction::lcm(int numerator, int denumerator) const
    {
        return (numerator * denumerator) / gcd(numerator, denumerator);
    }
}