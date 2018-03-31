// 由於每行有一皇后且唯一，所以使用行當作遞迴的index
// 另有vis[][]紀錄，列、副對角、主對角是否已有皇后
// 若行加列相等代表在同一副對角，以3x3為例
// 0 1 2
// 1 2 3
// 2 3 4
// 若列減行相等則在同一主對角，但因為陣列索引不能為負，所以統一加上n
//  0  1  2   +3    3 4 5
// -1  0  1  --->   2 3 4
// -2 -1  0         1 2 3

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int price[8][8];
int vis[3][14];
int C[8];
int mmax;

void search(int cur)
{
    // cur = 目前行
    if (cur == 8) {
        int sum = 0;
        for (int x = 0; x < 8; x++) {
            sum += price[x][C[x]];
            // printf("(%d,%d)", x, C[x]);
        }
        if (mmax < sum) {
            mmax = sum;
        }
    } else {
        for (int i = 0; i < 8; i++) {
            if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + 8]) {
                C[cur] = i;
                vis[0][i] = 1;              // 第i列
                vis[1][cur + i] = 1;        // 副對角
                vis[2][cur - i + 8] = 1;    // 主對角
                search(cur + 1);
                vis[0][i] = 0;
                vis[1][cur + i] = 0;
                vis[2][cur - i + 8] = 0;
            }
        }
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        while (n--) {
            mmax = 0;
            memset(vis, 0, sizeof(vis));
            memset(C, 0, sizeof(C));
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    scanf("%d", &price[i][j]);
                }
            }
            search(0);
            printf("%5d\n", mmax);
        }
    }
    return 0;
}
