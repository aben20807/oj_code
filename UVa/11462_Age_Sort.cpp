#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        int a[n];
        int i = 0, sn = n;
        while (sn--) {
            scanf("%d", &a[i++]);
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            if (i > 0)
                printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
