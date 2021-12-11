#include <iostream>
#include <functional>
using namespace std;

struct A {
  int a, b, c, d;
};

struct B {
  long a, b, c, d;
};

struct C {
  float a, b, c, d;
};

struct D {
  double a, b, c, d;
};

struct APlusB {
public:
  APlusB(int a, int b): a(a), b(b) {}

  int eval() {
    return a + b;
  }

private:
  int a, b;
};

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int a, b;
  cin >> a >> b;
  APlusB solver = APlusB(a, b);
  cout << "Struct: " << solver.eval() << endl;
  return 0;
}