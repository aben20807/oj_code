// LCS

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        int dp[s1.length() + 1][s2.length() + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= (int)s1.length(); i++) {
            for (int j = 1; j <= (int)s2.length(); j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        printf("%d\n", dp[s1.length()][s2.length()]);
    }
    return 0;
}
