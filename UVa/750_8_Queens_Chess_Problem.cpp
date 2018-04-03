// Backtracking 應用，跟 UVa 167 相似
// 不同的是會先填入一個位置，所以在 bt 中遇到已經填好的 col 就直接下一個
// 注意最後沒有空行

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int c, r;
bool vis[3][14];
int soln;
int ans[8];

void bt(int curc)
{
    if (curc == 8) {
        printf("%2d     ", soln++);
        for (int i : ans) {
            printf(" %d", (i + 1));
        }
        printf("\n");
    } else {
        if (curc == c) {
            bt(curc + 1);
        } else {
            for (int i = 0; i < 8; i++) {
                if (!vis[0][i] && !vis[1][curc + i] && !vis[2][curc - i + 8]) {
                    ans[curc] = i;
                    vis[0][i] = true;
                    vis[1][curc + i] = true;
                    vis[2][curc - i + 8] = true;
                    bt(curc + 1);
                    vis[0][i] = false;
                    vis[1][curc + i] = false;
                    vis[2][curc - i + 8] = false;
                }
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        soln = 1;
        memset(vis, false, sizeof(vis));
        scanf("%d%d", &r, &c);
        r--;
        c--;
        vis[0][r] = true;
        vis[1][c + r] = true;
        vis[2][c - r + 8] = true;
        ans[c] = r;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        bt(0);
        if (t) {
            printf("\n");
        }
    }
    return 0;
}
