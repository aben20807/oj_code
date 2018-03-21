#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        int dp[n + 1] = {0};
        dp[0] = 1;
        int v[5] = {1, 5, 10, 25, 50};
        for (int i = 0; i < 5; i++) {
            for (int j = v[i]; j < n + 1; j++) {
                if (dp[j - v[i]]) {
                    dp[j] += dp[j - v[i]];
                }
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
