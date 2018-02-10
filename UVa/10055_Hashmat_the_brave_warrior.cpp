#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    long long a, b;
    while (scanf("%lld%lld", &a, &b) != EOF) {
        printf("%lld\n", (b - a > 0) ? b - a : a - b);
    }
    return 0;
}
