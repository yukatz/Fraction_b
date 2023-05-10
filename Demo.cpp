/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(5,3), b(14,21);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a+b << endl; 
    cout << "a-b" << a-b << endl; 
    cout << "a/b" << a/b << endl; 
    cout << "a*b" << a*b << endl; 
    cout << "2.3*b" << 2.3*b << endl; 
    cout << "a+2.421" << a+2.421 << endl; 
    Fraction c = a+b-1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;



    std::cout<<"////////////////My demo part///////////////S"<<endl;
    Fraction s(1,2);
    cout<< (0.3 < s) << endl;
    cout<< (0.3 >= s) << endl;
    cout<< (1 > s) << endl;
    cout<< (1 <= s) << endl;
    cout<< (1 >= s) << endl;
    cout<< (1 < s) << endl;

    std::stringstream ss;
    ss.str("");
    Fraction neg_frac{-7, 9};
    ss << neg_frac;
    cout<<neg_frac<<endl;
    cout<<neg_frac.getNumerator()<<endl;
    cout<<neg_frac.getDenominator()<<endl;
    cout << "///////OverFlow/////////" << endl;

    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    Fraction f2(1, max_int);
    Fraction f4(max_int - 100, max_int);
    Fraction f5(max_int - 1, 1);
    Fraction f7(min_int + 1, 1);
    
    cout << "(f2 / f4): " <<(f2 / f4) << endl;
    cout << "(f2 * f4): " <<(f2 * f4) << endl;
    cout << "(f5 - f7): " <<(f5 - f7) << endl;

}
