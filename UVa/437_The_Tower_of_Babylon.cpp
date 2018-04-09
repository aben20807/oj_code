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

bool cmp(struct block b1, struct block b2)
{
    if (b1.x == b2.x)
        return b1.y >= b2.y;
    return b1.x >= b2.x;
}

int lds(vector<struct block> &b)
{
    if (b.size() == 0)
        return 0;
    int dp[b.size()];
    int dppath[b.size()];
    for (int i = 0; i < (int)b.size(); i++) {
        dp[i] = b[i].z;
        dppath[i] = -1;
    }
    for (int i : dp) {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < (int)b.size(); i++) {
        for (int j = i + 1; j < (int)b.size(); j++) {
            if (b[j].x < b[i].x && b[j].y < b[i].y && dp[i] + b[j].z > dp[j]) {
                dp[j] = dp[i] + b[j].z;
                dppath[j] = i;
            }
        }
    }
    for (int i : dp) {
        printf("%4d", i);
    }
    printf("\n");
    for (int i : dppath) {
        // printf("%3d", i);
    }
    printf("\n");
    int mmax = 0, pos = 0;
    for (int i = 0; i < (int)b.size(); i++) {
        if (mmax < dp[i]) {
            mmax = dp[i];
            pos = i;
        }
    }
    for (int i = pos; i != -1; i = dppath[i]) {
        // printf("%d ", b[i].z);
    }
    // printf("\n");
    return 0;
}

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        vector<struct block> b;
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
        for (int i = 0; i < (int)b.size(); i++) {
            // printf("%d %d %d\n", b[i].x, b[i].y, b[i].z);
        }
        lds(b);
    }
    return 0;
}
