// 輸入的每個磚塊都有六種的可能要比較，所以每讀x,y,z就把所有排列都列出來
// 接著從大到小排序後再去跑LDS
// 發現在cmp()裡面使用 >= 會出現上次迴圈中vector的東西，頗怪

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

struct block {
    int x;
    int y;
    int z;
};
vector<struct block> b;

bool cmp(struct block b1, struct block b2)
{
    if (b1.x == b2.x)
        return b1.y > b2.y; // BUG: >=
    return b1.x > b2.x;     // BUG: >=
}

int lds(vector<struct block> &b)
{
    if (b.size() == 0)
        return 0;
    int dp[b.size()];
    int mmax = 0;
    for (int i = 0; i < (int)b.size(); i++) {
        dp[i] = b[i].z;
        if (mmax < dp[i]) {
            mmax = dp[i];
        }
    }
    for (int i = 0; i < (int)b.size(); i++) {
        for (int j = i + 1; j < (int)b.size(); j++) {
            if (b[j].x < b[i].x && b[j].y < b[i].y && dp[i] + b[j].z > dp[j]) {
                dp[j] = dp[i] + b[j].z;
                if (mmax < dp[j]) {
                    mmax = dp[j];
                }
            }
        }
    }
    return mmax;
}

int main()
{
    int n, casecnt = 1;
    while (scanf("%d", &n) && n) {
        b.clear();
        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            b.push_back({x, y, z});
            b.push_back({x, z, y});
            b.push_back({y, x, z});
            b.push_back({y, z, x});
            b.push_back({z, x, y});
            b.push_back({z, y, x});
        }
        sort(b.begin(), b.end(), cmp);
        // for (auto b:b){ // BUG: use >= in cmp()
        //     printf("%d %d %d\n", b.x, b.y, b.z);
        // }
        printf("Case %d: maximum height = %d\n", casecnt++, lds(b));
    }
    return 0;
}
