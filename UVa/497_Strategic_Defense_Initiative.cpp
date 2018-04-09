// LIS
// 輸入一樣是不規則的，用一個空行間隔測資，所以一樣用 getline 並判斷長度
// 長度為 0 就是空行，其他用 atoi 轉成數字後存到 vector 中
// 注意輸出是用空行間隔

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

void lis(vector<int> &s)
{
    if (s.size() == 0)
        return;
    int pos[s.size()];
    memset(pos, 0, sizeof(pos));
    pos[0] = 1;
    vector<int> v;
    v.push_back(s[0]);
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
    printf("Max hits: %d\n", (int)v.size());
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
    int t;
    string tmps;
    scanf("%d\n", &t);
    while (t--) {
        vector<int> h;
        while (getline(cin, tmps)) {
            if (tmps.length() == 0) {
                break;
            }
            h.push_back(atoi(tmps.c_str()));
        }
        lis(h);
        if (t) {
            printf("\n");
        }
    }
    return 0;
}
