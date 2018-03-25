#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

// a   c
// - : -
// b   d

int main()
{
    long long a, b, c, d;
    while (~scanf("%lld %lld", &a, &b)) {
        double eps;
        scanf("%lf", &eps);
        for (d = 1; ; d++) {
            c = (long long)((long double)a / b * d);
            while (a * d >= b * c)
                c++;
            long double error =  ((long double)c) / ((long double)d)
                                 - ((long double)a) / ((long double)b);
            if (error <= eps) {
                printf("%lld %lld\n", c, d);
                break;
            }
        }
    }
    return 0;
}
