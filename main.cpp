#include <iostream>
#include "rational.h"

using namespace std;

int main(){
  Rational r = 7;
  Rational k(6, 4);
  Rational p;
  cin >> p;
  cout << p * r + k;
}
