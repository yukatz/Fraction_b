#include <iostream>
#include <string>

namespace ariel
{

    using namespace std;

    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        // Constructors
        Fraction();
        Fraction(int numerator, int denumerator);
        Fraction(double Fraction);
       

        void fractReduct();

        // Getters&Setters
        int getNumerator()const;
        int getDenominator()const;
        void setNum(int n);
        void setDenom(int n);


        // Overloading operators +,-,*,/
        // Fraction VS Fraction
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;

        // Fraction VS Number
        Fraction operator+(double number) const;
        Fraction operator-(double number) const;
        Fraction operator*(double number) const;
        Fraction operator/(double number) const;

        // Number VS Fraction
        friend Fraction operator+(double number, const Fraction &other);
        friend Fraction operator-(double number, const Fraction &other);
        friend Fraction operator*(double number, const Fraction &other);
        friend Fraction operator/(double number, const Fraction &other);

        // Overloading comperators ==,<,>,<=,>=
        // Fraction VS Fraction
        bool operator==(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator>(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;

        // Fraction VS Number
        bool operator==(double number) const;
        bool operator<(double number) const;
        bool operator>(double number) const;
        bool operator<=(double number) const;
        bool operator>=(double number) const;

        // Number VS Fraction
        friend bool operator==(double number, const Fraction &other);
        friend bool operator<(double number, const Fraction &other);
        friend bool operator>(double number, const Fraction &other);
        friend bool operator<=(double number, const Fraction &other);
        friend bool operator>=(double number, const Fraction &other);

        // Fraction ++/--
        friend Fraction operator++(Fraction &frac, int);
        friend Fraction operator--(Fraction &frac, int);

        //++/--Fraction
        const Fraction operator--();
        const Fraction operator++();

        // Consule In & Consule Out
        friend ostream &operator<<(ostream &outStrean, const Fraction &fraction);
        friend istream &operator>>(istream &inStream, Fraction &fraction);

        int lcm(int numerator, int denumerator) const;
        int gcd(int numerator, int denumerator) const;
    };
}