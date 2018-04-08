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
    for (int i = 0; i < (int)c.size(); i++) {
        for (int j = 0; j < (int)r.size(); j++) {
            // printf("%d ", dp[i][j]);
        }
        // printf("\n");
    }
    for (int i = 1; i < (int)c.size(); i++) {
        for (int j = 1; j < (int)r.size(); j++) {
            if (c[i] == r[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= (int)c.size(); i++) {
        for (int j = 0; j <= (int)r.size(); j++) {
            // printf("%d ", dp[i][j]);
        }
        // printf("\n");
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
            // memset(c, 0, sizeof(c));
            // c.clear();
            n = atoi(tmps.c_str());
            c.resize(n + 1);
            fill(c.begin(), c.end(), 0);
            // printf("%d\n", n);
            for (int i = 1; i <= n; i++) {
                int tmpn;
                scanf("%d", &tmpn);
                c[tmpn] = i;
            }
            for (int i = 0; i < n; i++) {
                // printf("%d ", c[i]);
            }
            // printf("\n");
        } else if (tmps.length() > 0) {
            stringstream ss(tmps);
            vector<int> r(n + 1);
            fill(r.begin(), r.end(), 0);
            int tmpn, index = 1;
            while (ss >> tmpn) {
                // printf("%d ", tmpn);
                // r.push_back(tmpn);
                r[tmpn] = index++;
            }
            for (int i : c) {
                // printf("%d ", i);
            }
            // printf("\n");
            for (int i : r) {
                // printf("%d ", i);
            }
            // printf("\n");
            printf("%d\n", lcs(c, r));
        }
    }
    return 0;
}
