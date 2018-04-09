// LIS
// 用O(N^2) 會 TLE，使用 O(NlogL) 的方法
// 利用 pos 記錄位置，然後從後面往前找出最後符合的 LIS
// 因為會倒序所以先用 ans 儲存再輸出

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

vector<int> a;

void lis(vector<int>& s)
{
    if (s.size() == 0)
        return;
    vector<int> v;
    v.push_back(s[0]);
    int pos[s.size()];
    memset(pos, 0, sizeof(pos));
    pos[0] = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        int tmp = s[i];
        if (tmp > v.back()) {
            pos[i] = v.size() + 1;
            v.push_back(tmp);
        } else {
            auto it = lower_bound(v.begin(), v.end(), tmp);
            pos[i] = it - v.begin() + 1;
            *it = tmp;
        }
    }
    printf("%d\n-\n", (int)v.size());
    int len = v.size();
    vector<int> ans;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (pos[i] == len) {
            ans.push_back(s[i]);
            len--;
        }
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
