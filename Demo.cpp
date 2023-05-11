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

    long long max_int = std::numeric_limits<int>::max();
    long long min_int = std::numeric_limits<int>::min();

    Fraction f5(max_int - 1, 1);
    Fraction f7(min_int + 1, 1);
    Fraction f4(max_int - 100, max_int);
    Fraction f3(max_int, max_int);

    cout << "(f5 - f7): " <<static_cast<long long>((max_int - 1)-(min_int + 1)) << endl;
    cout << "(f4 / f3): " <<static_cast<long long>(static_cast<double>(max_int - 100)/ static_cast<double>(max_int)) << endl;
    cout << "(f4 * f3): " <<(f4 * f3) << endl;

    cout << "(f4 / f3): " <<(f4 / f3) << endl;
    
    
    cout << "(f5 - f7): " <<(f5 - f7) << endl;


}
