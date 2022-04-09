#include "rational.h"  // check include guards
#include <istream>

Rational::Rational(int num, int d) {
  SetNumeratorDenominator(num, d);
}


Rational::Rational(int num) {
  numerator = num;
  denominator = 1;
}

Rational::Rational() {
  numerator = 0;
  denominator = 1;
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

void Rational::SetNumerator(const int &num) {
  numerator = num;
  StandartView();
}

void Rational::SetDenominator(const int &d) {
  if (!d) {
    throw RationalDivisionByZero{};
  }
  denominator = d;
  StandartView();
}

void Rational::SetNumeratorDenominator(const int &num, const int &d) {
  if (!d) {
    throw RationalDivisionByZero{};
  }
  numerator = num;
  denominator = d;
  StandartView();
}
int Rational::GetNumerator() const {
  return numerator;
}

int Rational::GetDenominator() const {
  return denominator;
}

std::ostream &operator<<(std::ostream &out, const Rational &num) {
  out << num.numerator;
  if (num.denominator != 1) {
    out << "/" << num.denominator;
  }
  return out;
}

std::istream &operator>>(std::istream &in, Rational &num) {
  std::string s;
  in >> s;

  int numerator = 0, denominator = 0, numerator_m = 1, denominator_m = 1;
  bool one_num = true;
  for (char c : s) {
    if (c == '/') {
      one_num = false;
    } else if (one_num) {
      if (c == '-') {
        numerator_m *= -1;
      } else {
        numerator = numerator * 10 + (c - '0');
      }
    } else {
      if (c == '-') {
        denominator_m *= -1;
      } else {
        denominator = denominator * 10 + (c - '0');
      }
    }
  }

  num.SetNumeratorDenominator(numerator * numerator_m, denominator * denominator_m);

  return in;

  return in;
}

Rational Rational::operator+(const Rational &other) const {
  return {numerator * other.denominator + other.numerator * denominator, denominator * other.denominator};
}

Rational Rational::operator-(const Rational &other) const {
  return *this + (-other);
}

Rational &Rational::operator+=(const Rational &other) {
  *this = *this + other;
  return *this;
}

Rational &Rational::operator-=(const Rational &other) {
  *this = *this - other;
  return *this;
}

Rational Rational::operator*(const Rational &other) const {
  return {numerator * other.numerator, other.denominator * denominator};
}

Rational &Rational::operator*=(const Rational &other) {
  *this = *this * other;
  return *this;
}

Rational Rational::operator/(const Rational &other) const {
  if (other == 0) {
    throw RationalDivisionByZero{};
  }
  return (*this * Rational(other.denominator, other.numerator));
}

Rational &Rational::operator/=(const Rational &other) {
  *this = *this / other;
  return *this;
}

Rational Rational::operator-() const {
  return {this->numerator * -1, this->denominator};
}

Rational Rational::operator+() const {
  return *this;
}

Rational operator+(const int &num, const Rational &r) {
  return Rational(num) + r;
}

Rational operator-(const int &num, const Rational &r) {
  return Rational(num) - r;
}

Rational operator*(const int &num, const Rational &r) {
  return Rational(num) * r;
}

Rational operator/(const int &num, const Rational &r) {
  return Rational(num) / r;
}

Rational &Rational::operator++() {
  return *this += 1;
}

Rational Rational::operator++(int) {
  auto ret = *this;
  *this += 1;
  return ret;
}

Rational &Rational::operator--() {
  return *this -= 1;
}

Rational Rational::operator--(int) {
  auto ret = *this;
  *this -= 1;
  return ret;
}

bool Rational::operator<(const Rational &other) const {
  return numerator * other.denominator < denominator * other.numerator;
}

bool Rational::operator==(const Rational &other) const {
  return numerator == other.numerator && denominator == other.denominator;
}

bool Rational::operator!=(const Rational &other) const {
  return !(*this == other);
}

bool Rational::operator>(const Rational &other) const {
  return !(*this < other || *this == other);
}

bool Rational::operator>=(const Rational &other) const {
  return !(*this < other);
}

bool Rational::operator<=(const Rational &other) const {
  return !(*this > other);
}

bool operator==(const int &num, const Rational &r) {
  return Rational(num) == r;
}

bool operator!=(const int &num, const Rational &r) {
  return Rational(num) != r;
}

bool operator<(const int &num, const Rational &r) {
  return Rational(num) < r;
}

bool operator>(const int &num, const Rational &r) {
  return Rational(num) > r;
}

bool operator<=(const int &num, const Rational &r) {
  return Rational(num) <= r;
}

bool operator>=(const int &num, const Rational &r) {
  return Rational(num) >= r;
}