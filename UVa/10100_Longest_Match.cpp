// 因為只有接受數字和字母，所以其他字元都是分隔符號
// 我就事先把非數字非字母的都變成空白，方便 stringstream 分割單字
// 輸入的兩行字串有一行是空行就要輸出 Blank!
// 注意輸出格式，case 記數需要用 %2d 輸出

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
    int casecnt = 1;
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        if (s1.length() == 0 || s2.length() == 0) {
            printf("%2d. Blank!\n", casecnt++);
            continue;
        }
        for (char &c : s1) {
            if (isalpha(c) || isdigit(c)) {
            } else {
                c = ' ';
            }
        }
        for (char &c : s2) {
            if (isalpha(c) || isdigit(c)) {
            } else {
                c = ' ';
            }
        }
        vector<string> t1, t2;
        stringstream ss1(s1);
        string tmps;
        while (ss1 >> tmps) {
            t1.push_back(tmps);
        }
        stringstream ss2(s2);
        while (ss2 >> tmps) {
            t2.push_back(tmps);
        }
        int dp[t1.size() + 1][t2.size() + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= (int)t1.size(); i++) {
            for (int j = 1; j <= (int)t2.size(); j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
                // printf("%d ", dp[i][j]);
            }
            // printf("\n");
        }
        printf("%2d. Length of longest match: %d\n", casecnt++,
               dp[t1.size()][t2.size()]);
    }
    return 0;
}
