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
        Fraction(int a, int b);
        Fraction(double num);

        void fractReduct();



        // Getters&Setters
        int getNum();
        int getDenom();
        void setNum(int n);
        void setDenom(int n);

        // toString
        string fractToString();

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
        Fraction &operator++(int number);
        Fraction &operator--(int number);

        //++/--Fraction
        Fraction operator--();
        Fraction operator++();

        // Consule In & Consule Out
        friend ostream &operator<<(ostream &os, const Fraction &f);
        friend istream &operator>>(istream &is, Fraction &f);

        int lcm(int a, int b) const;
        int gcd(int a, int b) const;
    };
};