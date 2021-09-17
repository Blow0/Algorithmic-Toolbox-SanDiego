#include <iostream>

long long lcm_naive(int a, int b) 
{
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
int gcd_fast(int a, int b) {
  if(a == 0)
    return b;
  if(b == 0)
    return a;
  
  return gcd_fast(b, a%b);    
}

long long lcm_fast(int a, int b) 
{
  int divisor = gcd_fast(a, b);
  int a1 = a / divisor;
  int b1 = b / divisor;


  return (long long) b1 * a;
}

int main() {
  int a, b;
  int min, max;
  std::cin >> a >> b;
  if(a > b)
  {
    max = a; min = b;
  }
  else
  {
    min = a; max = b;
  }
   
  //std::cout << lcm_naive(a, b) << std::endl;  
  std::cout << lcm_fast(max, min) << std::endl;
  return 0;
}
