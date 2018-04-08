// 輸入方式有點麻煩，因為每筆測資並沒有說有幾行學生的陣列
// 所以就每行都以 getline 方式讀入，判斷是否有空白，若沒有就是 n 了
// 輸入的陣列也不是直接餵到 lcs，因為讀到的是第i個排在哪個位置
// 例如：2, 3, 1 代表第1個數排在第二個位置，真正數列是 3, 1, 2
// 接著就是一般 LCS 了

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

int lcs(vector<int> c, vector<int> r)
{
    int dp[c.size() + 1][r.size() + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < (int)c.size(); i++) {
        for (int j = 1; j < (int)r.size(); j++) {
            if (c[i] == r[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[c.size() - 1][r.size() - 1];
}

int main()
{
    string tmps;
    int n = 0;
    vector<int> c;
    while (getline(cin, tmps)) {
        if (tmps.length() > 0 && (int)tmps.find(" ") == -1) {
            n = atoi(tmps.c_str());
            c.resize(n + 1);
            fill(c.begin(), c.end(), 0);
            for (int i = 1; i <= n; i++) {
                int tmpn;
                scanf("%d", &tmpn);
                c[tmpn] = i;
            }
        } else if (tmps.length() > 0) {
            stringstream ss(tmps);
            vector<int> r(n + 1);
            fill(r.begin(), r.end(), 0);
            int tmpn, index = 1;
            while (ss >> tmpn) {
                r[tmpn] = index++;
            }
            printf("%d\n", lcs(c, r));
        }
    }
    return 0;
}
