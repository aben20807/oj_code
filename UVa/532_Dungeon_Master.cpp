#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

char m[31][31][31];
int vis[31][31][31];
int dis[31][31][31];
// north{0, -1, 0}, south{0, 1, 0}, east{0, 0, 1}, west{0, 0, -1},
// up{1, 0, 0}, down{-1, 0, 0}
int dir[6][3] = {{0, -1, 0}, {0, 1, 0}, {0, 0, 1},
    {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}
};
int l, r, c;

void bfs(int z, int i, int j, int z_end, int i_end, int j_end)
{
    queue<tuple<int, int, int>> q;
    tuple<int, int, int> root(z, i, j);
    vis[z][i][j] = 1;
    q.push(root);
    while (!q.empty()) {
        int z_cur = get<0>(q.front());
        int i_cur = get<1>(q.front());
        int j_cur = get<2>(q.front());
        // printf("%d, %d, %d\n", z_cur, i_cur, j_cur);
        q.pop();
        if (z_cur == z_end && i_cur == i_end && j_cur == j_end) {
            return;
        }
        for (int x = 0; x < 6; x++) {
            int z_next = z_cur + dir[x][0];
            int i_next = i_cur + dir[x][1];
            int j_next = j_cur + dir[x][2];
            if (z_next < 0 || z_next >= l || i_next < 0 || i_next >= r ||
                j_next < 0 || j_next >= c ||
                vis[z_next][i_next][j_next] || m[z_next][i_next][j_next] == '#')
                continue;
            dis[z_next][i_next][j_next] = dis[z_cur][i_cur][j_cur] + 1;
            vis[z_next][i_next][j_next] = 1;
            tuple<int, int, int> next(z_next, i_next, j_next);
            q.push(next);
        }
    }
}

int main()
{
    l = 0;
    r = 0;
    c = 0;
    while (scanf("%d%d%d", &l, &r, &c)) {
        if (l == 0 && r == 0 && c == 0)
            break;
        memset(m, '0', sizeof(m));
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        int f_z = 0, f_i = 0, f_j = 0, e_z = 0, e_i = 0, e_j = 0;
        for (int z = 0; z < l; z++) {
            for (int i = 0; i < r; i++) {
                scanf("%s", m[z][i]);
                for (int j = 0; j < c; j++) {
                    if (m[z][i][j] == 'S') {
                        f_z = z;
                        f_i = i;
                        f_j = j;
                    }
                    if (m[z][i][j] == 'E') {
                        e_z = z;
                        e_i = i;
                        e_j = j;
                    }
                }
            }
        }
        bfs(f_z, f_i, f_j, e_z, e_i, e_j);
        int ans = dis[e_z][e_i][e_j];
        if (ans > 0)
            printf("Escaped in %d minute(s).\n", ans);
        else
            printf("Trapped!\n");
    }
    return 0;
}
