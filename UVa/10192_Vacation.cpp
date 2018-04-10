// LCS

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int casecnt = 1;
    string s1, s2;
    while (getline(cin, s1)) {
        if (s1[0] == '#')
            break;
        getline(cin, s2);
        // printf("%s\n%s\n", s1.c_str(), s2.c_str());
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
        printf("Case #%d: you can visit at most %d cities.\n",
               casecnt++,
               dp[s1.length()][s2.length()]);
    }
    return 0;
}
