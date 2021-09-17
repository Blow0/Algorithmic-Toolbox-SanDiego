#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0;
  int eq = m / 10;
  if(eq != 0)
  {
    n += eq;
    m = m - eq*10;
  }
  eq = m / 5;
  if(eq != 0)
  {
    n += eq;
    m = m - eq*5;
  }
  n += m;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
