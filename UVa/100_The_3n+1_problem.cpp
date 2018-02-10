#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    long long i, j;
    while (scanf("%lld%lld", &i, &j) != EOF) {
        printf("%lld %lld ", i, j);
        if (i > j) {
            int t = i;
            i = j;
            j = t;
        }
        long long max_l = 0;
        for (int c = i; c <= j; c++) {
            long long length = 1;
            long long n = c;
            while (n != 1) {
                if (n % 2 == 1)
                    n = 3 * n + 1;
                else
                    n /= 2;
                length++;
            }
            if (length > max_l)
                max_l = length;
        }
        printf("%lld\n", max_l);
    }
    return 0;
}
