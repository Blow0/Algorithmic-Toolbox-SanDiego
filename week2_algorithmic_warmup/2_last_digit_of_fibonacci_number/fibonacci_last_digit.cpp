#include <iostream>
#include <cassert>
#include <stdint.h>

uint8_t f[10000001];

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int get_fibonacci_last_digit_fast(int n) 
{
    for (int i = 2; i <= n; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % 10; //store only last digits
    return f[n];
}
void test_solution() {
    for (int n = 0; n < 20; ++n)
        assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
}
int main() 
{
    int n;
    f[0] = 0;
    f[1] = 1;
    std::cin >> n;
    std::cout << get_fibonacci_last_digit_fast(n) << '\n';
    return 0;
}
