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

    Rational (int _numerator, int _denominator){
        numerator = _numerator;
        denominator = _denominator;
        if (-denominator == 0){
            ///
        }
        standart_view();
    }

    Rational(int num){
        numerator = num;
        denominator = 1;
    }

    Rational(){
        numerator = 0;
        denominator = 1;
    }

    int GetNumerator(){
        return numerator;
    }

    int GetDenominator(){
        return denominator;
    }

    void SetNumerator(int _num){
        numerator = _num;
        standart_view();
    }

    void SetDenominator(int _denum){
        denominator = _denum;
        standart_view();
    }

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

    Rational operator+(Rational other) {
        return *Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator).standart_view();
    }

    Rational operator-() {
        return Rational(this->numerator * -1, this->denominator);
    }

    Rational operator-(Rational other) {
        return *this + (-other);
    }

//    Rational operator+(Rational other)   Что тут писать

    Rational operator++(int _){
        auto ret = *this;
        *this += 1;
        standart_view();
        return ret;
    }

    Rational operator++(){
        return *(*this += 1).standart_view();
    }

    Rational operator--(int _){
        auto ret = *this;
        *this -= 1;
        standart_view();
        return ret;
    }

    Rational operator--(){
        return *(*this -= 1).standart_view();
    }

    Rational operator*(Rational other){
        return *Rational(numerator * other.numerator, denominator * other.denominator).standart_view();
    }

    Rational operator/(Rational other){
        return *(*this * Rational(other.denominator, other.numerator)).standart_view();
    }

    Rational operator+=(Rational other){
        *this = *this + other;
        return *this;
    }

    Rational operator-=(Rational other){
        *this = *this - other;
        return *this;
    }

    Rational operator*=(Rational other){
        *this = *this * other;
        return *this;
    }

    Rational operator/=(Rational other){
        *this = *this / other;
        return *this;
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
    Rational c = 11;
    r++;
    c--;
    cout << ++r << " " << --c;
    return 0;
}
