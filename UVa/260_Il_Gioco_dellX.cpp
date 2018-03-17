#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
char board[201][201];
int vis[201][201];
int dir[6][2] = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};

void dfs(int i, int j, char c, int& win)
{
    vis[i][j] = 1;
    if (c == 'b' && i == n - 1) win = 1;
    if (c == 'w' && j == n - 1) win = 2;
    for (int x = 0; x < 6; x++) {
        int i_next = i + dir[x][0];
        int j_next = j + dir[x][1];
        if (i_next < 0 || i_next >= n || j_next < 0 || j_next >= n ||
            vis[i_next][j_next])
            continue;
        if (board[i_next][j_next] == c)
            dfs(i_next, j_next, c, win);
    }
}

int main()
{
    int casecnt = 1;
    while (scanf("%d", &n) && n) {
        memset(board, '0', sizeof(board));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i ++) {
            scanf("%s", board[i]);
        }
        int win = 0;
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'w') {
                dfs(i, 0, 'w', win);
                // printf("%d\n", win);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'b') {
                dfs(0, i, 'b', win);
                // printf("%d\n", win);
            }
        }
        if (win == 1) {
            printf("%d %c\n", casecnt++, 'B');
        } else if (win == 2) {
            printf("%d %c\n", casecnt++, 'W');
        }
    }
    return 0;
}
