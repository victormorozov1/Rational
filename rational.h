#include <algorithm>

class Rational{
public:
    int numerator, denominator;

    Rational (int _numerator, int _denominator){
        SetNumerator(_numerator);
        SetDenominator(_denominator);
    }

    Rational(int num){ // NOLINT
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
        ///if (!_denum)
        ///    throw RationalDivisionByZero{};  // Это нужно будет вставить при отправке
        denominator = _denum;
        standart_view();
    }

    Rational* standart_view(){
        if (denominator < 0){
            denominator *= -1;
            numerator *= -1;
        }

        int nod = std::__gcd(abs(numerator), abs(denominator));
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

    bool operator==(Rational other){
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(Rational other){
        return !(*this == other);
    }
};

std::ostream& operator<< (std::ostream &out, const Rational &num)
{
    out << num.numerator;
    if (num.denominator != 1)
        out << "/" << num.denominator;
    return out;
}

std::istream& operator>> (std::istream &in, Rational &num)
{
    std::string s;
    in >> s;

    int numerator = 0, denominator = 0, numerator_m = 1, denominator_m = 1;
    bool one_num = true;
    for (char c : s){
        if (c == '/')
            one_num = false;
        else if (one_num) {
            if (c == '-')
                numerator_m *= -1;
            else
                numerator = numerator * 10 + (c - '0');
        }
        else {
            if (c == '-')
                denominator_m *= -1;
            else
                denominator = denominator * 10 + (c - '0');
        }
    }

    num.numerator = numerator * numerator_m;
    num.denominator = denominator?denominator * denominator_m:1;
    num.standart_view();

    return in;
}