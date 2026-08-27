#include <stdio.h>

/* Project Euler Problem 12: Highly Divisible Triangular Number
 * What is the value of the first triangle number to have over five
 * hundred divisors?
 */

long long countDivisors(long long n) {
    long long count = 1;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int exponent = 0;
            while (n % p == 0) {
                n /= p;
                exponent++;
            }
            count *= (exponent + 1);
        }
    }
    if (n > 1) {
        count *= 2;
    }
    return count;
}

int main(void) {
    long long n = 1;
    long long triangle = 1;

    while (1) {
        /* triangle number n(n+1)/2: split into coprime factors n and (n+1)
         * (one of them halved) to keep divisor counting fast */
        long long a = n;
        long long b = n + 1;
        long long divisors;
        if (a % 2 == 0) {
            divisors = countDivisors(a / 2) * countDivisors(b);
        } else {
            divisors = countDivisors(a) * countDivisors(b / 2);
        }

        triangle = a * b / 2;

        if (divisors > 500) {
            printf("%lld\n", triangle);
            break;
        }
        n++;
    }

    return 0;
}
