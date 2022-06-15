#include <stdio.h>

long long fib(long long n) {
  if(n <= 1) {
    return n;
  }

  return fib(n - 1) + fib(n - 2);
}

int main() {
  long long n = 50;

  printf("fib(%lld): %lld\n", n, fib(n));
}

/* gcc fib.c -Wall -o fib && time ./fib */

/* fib(40): 102334155 */
/* ./a.out  0.60s user 0.00s system 99% cpu 0.608 total */

/* fib(50): 12586269025 */
/* ./fib  79.99s user 0.56s system 98% cpu 1:22.06 total */
