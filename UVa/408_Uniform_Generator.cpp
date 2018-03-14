#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int s, m;
    while (scanf("%d%d", &s, &m) != EOF) {
        printf("%10d%10d    ", s, m);
        if (gcd(s, m) == 1) {
            printf("Good Choice\n\n");
        } else {
            printf("Bad Choice\n\n");
        }
    }
    return 0;
}
