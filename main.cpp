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

    Rational* standart_view(){
        if (denominator < 0){
            denominator *= -1;
            numerator *= -1;
        }

        int nod = NOD(abs(numerator), abs(denominator));
        numerator /= nod;
        denominator /= nod;

        return this;
    }

    Rational (int _numerator, int _denominator){
        numerator = _numerator;
        denominator = _denominator;
        standart_view();
    }

    Rational operator+(Rational other) {
        return *Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator).standart_view();
    }

    Rational operator-() {
        return Rational(this->numerator * -1, this->denominator);
    }

    Rational operator-(Rational& other) {
        return *this + (-other);
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
    Rational r(-9, 2), t(6, 3);
    cout << r + t;
    return 0;
}
