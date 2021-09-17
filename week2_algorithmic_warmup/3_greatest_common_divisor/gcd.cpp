#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
int gcd_fast(int a, int b) {
  if(a == 0)
    return b;
  if(b == 0)
    return a;
  
  return gcd_fast(b, a%b);    
}

int main() {
  int a, b, max, min;
  std::cin >> a >> b;
  if(a > b)
  {
    max = a;
    min = b;
  }
  else
    {
    max = b;
    min = a;
    }
  std::cout << gcd_fast(max, min) << std::endl;
  return 0;
}
