#include <stdio.h>

#define MAX_N 255

long long memo[MAX_N + 1];

long long fib(long long n) {
  if(n <= 1) {
    return n;
  }

  if (memo[n] != 0) {
    return memo[n];
  }

  return memo[n] = fib(n - 1) + fib(n - 2);
}

int main() {
  for (long long n = 1; n < 43; n++) {
    printf("fib(%lld): %lld\n", n, fib(n));
  }
}


/* with memo */

/* fib(42): 267914296 */
/* ./memo  0.00s user 0.00s system 1% cpu 0.209 total */

/* without memo */

/* fib(42): 267914296 */
/* ./memo  4.18s user 0.02s system 95% cpu 4.410 total */
