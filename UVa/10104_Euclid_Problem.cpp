#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int ex_gcd(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        int gcd = ex_gcd(b, a % b, x, y);
        int tmp = x;
        x = y;
        y = tmp - (a / b) * y;
        return gcd;
    }
}

int main()
{
    int a, b;
    int x = 0, y = 0;
    while (scanf("%d%d", &a, &b) != EOF) {
        int gcd = ex_gcd(a, b, x, y);
        printf("%d %d %d\n", x, y, gcd);
    }
    return 0;
}
