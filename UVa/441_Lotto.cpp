#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int vis[14];
int s[14];
int ans[6];
int k;

void bt(int digit, int index)
{
    vis[index] = 1;
    ans[digit] = s[index];
    for (int i = index + 1; i < k; i++) {
        if (!vis[i] && digit < 5) {
            bt(digit + 1, i);
        }
    }
    if (digit == 5) {
        for (int i = 0; i < 6; i++) {
            if (i > 0)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    vis[index] = 0;
    return;
}

int main()
{
    int isfirst = 1;
    while (scanf("%d", &k) && k) {
        for (int i = 0; i < 14; i++) {
            vis[i] = 0;
        }
        for (int i = 0; i < 6; i++) {
            ans[i] = 0;
        }
        for (int i = 0; i < k; i++) {
            scanf("%d", &s[i]);
        }
        if (!isfirst) {
            printf("\n");
        }
        isfirst = 0;
        for (int i = 0; i < k; i++) {
            bt(0, i);
        }
    }
    return 0;
}
