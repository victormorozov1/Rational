#include <iostream>

using namespace std;

int NOD(int a, int b){
    while (b){
        int ost = a % b;
        a = b;
        b = ost;
    }
    return a;
}

class Rational{
public:
    int numerator, denominator;

    Rational* short_fraction(){
        int nod = NOD(numerator, denominator);
        numerator /= nod;
        denominator /= nod;
        return this;
    }

    Rational (int _numerator, int _denominator){
        numerator = _numerator;
        denominator = _denominator;
        short_fraction();
    }

    Rational operator+(Rational& other) {
        return *Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator).short_fraction();
    }

};

std::ostream& operator<< (std::ostream &out, const Rational &num)
{
    out << num.numerator;
    if (num.denominator != 1)
        out << "/" << num.denominator;
    return out;
}

int main() {
    Rational r(9, 2), t(6, 3);
    cout << r + t;
    return 0;
}
