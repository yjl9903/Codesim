#include <iostream>
#include <functional>
using namespace std;

int main() {
  auto add = []() {
    int a, b;
    cin >> a >> b;
    return a + b;
  };
  cout << add() << endl;
  return 0;
}