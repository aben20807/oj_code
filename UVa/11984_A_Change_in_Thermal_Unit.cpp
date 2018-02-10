#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    int i = 1;
    scanf("%d", &n);
    while (n--) {
        int c, d;
        scanf("%d%d", &c, &d);
        double a_c = (double)c + (double)d * 5 / 9;
        printf("Case %d: %.2lf\n", i++, a_c);
    }
    return 0;
}
