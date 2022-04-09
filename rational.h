#pragma once
#include <algorithm>
#include <stdexcept>
#include <iostream>

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

class Rational {
 public:
  int numerator, denominator;

  Rational();
  Rational(int num);  // NOLINT
  Rational(int num, int d);

  Rational *StandartView();

  friend std::ostream &operator<<(std::ostream &out, const Rational &num);
  friend std::istream &operator>>(std::istream &in, Rational &num);

  int GetNumerator() const;
  int GetDenominator() const;
  void SetNumerator(const int &num);
  void SetDenominator(const int &d);
  void SetNumeratorDenominator(const int &num, const int &d);

  Rational operator+(const Rational &other) const;
  Rational &operator+=(const Rational &other);
  Rational operator-(const Rational &other) const;
  Rational &operator-=(const Rational &other);
  Rational operator*(const Rational &other) const;
  Rational &operator*=(const Rational &other);
  Rational operator/(const Rational &other) const;
  Rational &operator/=(const Rational &other);
  Rational operator-() const;
  Rational operator+() const;

  friend Rational operator+(const int &num, const Rational &r);
  friend Rational operator-(const int &num, const Rational &r);
  friend Rational operator*(const int &num, const Rational &r);
  friend Rational operator/(const int &num, const Rational &r);

  Rational &operator++();
  Rational operator++(int);
  Rational &operator--();
  Rational operator--(int);

  bool operator<(const Rational &other) const;
  bool operator>(const Rational &other) const;
  bool operator>=(const Rational &other) const;
  bool operator<=(const Rational &other) const;
  bool operator==(const Rational &other) const;
  bool operator!=(const Rational &other) const;

  friend bool operator==(const int &num, const Rational &r);
  friend bool operator!=(const int &num, const Rational &r);
  friend bool operator<(const int &num, const Rational &r);
  friend bool operator>(const int &num, const Rational &r);
  friend bool operator<=(const int &num, const Rational &r);
  friend bool operator>=(const int &num, const Rational &r);
};
