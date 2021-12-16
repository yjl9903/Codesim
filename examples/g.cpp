#include <iostream>
#include <string>
#include <sstream>

int g(int *a, int n) {
  int i = 0, sum = 0;
  while (i < n) { sum = sum + *(a + i); i++; }
  return sum;
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
  int s = g(a, n);
  std::cout << s << std::endl;
  return 0;
}