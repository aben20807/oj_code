#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    while (scanf("%lld", &n) && n >= 0) {
        for (long long i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                printf("    %lld\n", i);
                n /= i;
                i--;
            }
        }
        printf("    %lld\n\n", n);
    }
    return 0;
}
