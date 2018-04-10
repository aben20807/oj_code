// LCS

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int n1, n2, casecnt = 1;
    while (scanf("%d%d", &n1, &n2)) {
        if (n1 == 0 && n2 == 0)
            break;
        int l1[n1];
        int l2[n2];
        for (int &i : l1) {
            scanf("%d", &i);
        }
        for (int &i : l2) {
            scanf("%d", &i);
        }
        int dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (l1[i - 1] == l2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        printf("Twin Towers #%d\n", casecnt++);
        printf("Number of Tiles : %d\n\n", dp[n1][n2]);
    }
    return 0;
}
