#include <iostream>
#include <string>
#include <sstream>

int f(int *a, int n) {
  int s = 0;
  for (int i = 0; i < n; s += a[i++]);
  return s;
}

int main(int argc, char *argv[]) {
  int n = argc - 1;
  int *a = new int[n];
  std::stringstream ss;
  for (int i = 0; i < n; i++) {
    std::string s(argv[i+1]);
    ss << s;
    ss >> a[i];
    ss.clear();
  }
  int s = f(a, n);
  std::cout << s << std::endl;
  return 0;
}