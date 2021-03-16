#include <iostream>
#include "point.h"

using namespace std;

int main() {
  Point a(1, 2);
  Point b(3, 4);
  cout << "-a: " << -a << endl;
  cout << a + b << endl;
  cout << a - b << endl;
  cout << "--a: " << --a << endl;
  cout << "a++: " << a++ << endl;
  cout << "a: " << a << endl;
  cout << "a += b: " << (a += b) << endl;
  return 0;
}
