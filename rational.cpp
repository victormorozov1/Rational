#include "Rational.h"
#include <istream>

Rational::Rational(int num, int denom) {
  SetNumeratorDenominator(num, denom);
}

Rational::Rational(int num) {
  numerator = num;
  denominator = 1;
}

Rational::Rational() {
  numerator = 0;
  denominator = 1;
}
void Rational::SetDenominator(const int &denum) {
  if (!denum) {
    throw RationalDivisionByZero{};
  }
  denominator = denum;
  StandartView();
}
void Rational::SetNumerator(const int &num) {
  numerator = num;
  StandartView();
}
Rational *Rational::StandartView() {
  if (denominator < 0) {
    denominator *= -1;
    numerator *= -1;
  }

  int nod = std::__gcd(abs(numerator), abs(denominator));
  numerator /= nod;
  denominator /= nod;

  return this;
}
void Rational::SetNumeratorDenominator(const int &num, const int &denom) {
  numerator = num;
  denominator = denom;
  StandartView();
}
std::ostream &operator<<(std::ostream &out, const Rational &num) {
  out << num.numerator;
  if (num.denominator != 1)
    out << "/" << num.denominator;
  return out;
}
std::istream &operator>>(std::istream &in, Rational &num) {
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

  num.SetNumerator(numerator * numerator_m);
  num.SetDenominator(denominator?denominator * denominator_m:1);

  return in;
}

/*
int GetNumerator() const {
  return numerator;
}

int GetDenominator() const {
  return denominator;
}




Rational::Rational operator+(Rational other) const {
  return {numerator * other.denominator + other.numerator * denominator, denominator * other.denominator};
}

Rational::Rational operator-() const {
  return {this->numerator * -1, this->denominator};
}

Rational::Rational operator-(Rational other) const {
  return *this + (-other);
}

///    Rational operator+(Rational other)   Что тут писать

Rational::Rational operator++(int _) {
  auto ret = *this;
  *this += 1;
  return ret;
}

Rational::Rational operator++() {
  return *this += 1;
}

Rational::Rational operator--(int _) {
  auto ret = *this;
  *this -= 1;
  return ret;
}

Rational::Rational operator--() {
  return *this -= 1;
}

Rational::Rational operator*(Rational other) const {
  return {numerator * other.numerator, denominator * other.denominator};
}

Rational::Rational operator/(Rational other) const {
  return (*this * Rational(other.numerator, other.denominator));
}

Rational::Rational operator+=(Rational other) {
  *this = *this + other;
  return *this;
}

Rational::Rational operator-=(Rational other) {
  *this = *this - other;
  return *this;
}

Rational::Rational operator*=(Rational other) {
  *this = *this * other;
  return *this;
}

Rational::Rational operator/=(Rational other) {
  *this = *this / other;
  return *this;
}

Rational::bool operator==(Rational other) const {
  return numerator == other.numerator && denominator == other.denominator;
}

Rational::bool operator!=(Rational other) const {
  return !(*this == other);
}*/