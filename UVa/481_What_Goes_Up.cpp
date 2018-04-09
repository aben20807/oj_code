#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> a;

void lis(vector<int> s)
{
    if (s.size() == 0)
        return;
    vector<int> v;
    int dp[s.size()];
    int pre[s.size()];
    for (int i = 0; i < (int)s.size(); i++) {
        dp[i] = 1;
        pre[i] = -1;
    }
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = i + 1; j < (int)s.size(); j++) {
            if (s[j] > s[i]) {
                if (dp[j] <= dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                    pre[j] = i;
                }
            }
        }
    }
    int mmax = 0, pos = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (mmax <= dp[i]) {
            mmax = dp[i];
            pos = i;
        }
    }
    printf("%d\n-\n", mmax);
    vector<int> ans;
    for (int i = pos; i != -1; i = pre[i]) {
        ans.push_back(s[i]);
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d\n", ans[i]);
    }
}

int main()
{
    a.clear();
    int tmpn;
    while (~scanf("%d", &tmpn)) {
        a.push_back(tmpn);
    }
    lis(a);
    return 0;
}
