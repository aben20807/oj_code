#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>      // std::pair
#include <cstring>      // memset
#define i first
#define j second
using namespace std;

//  x x     (i-1,j-2), (i+1,j-2)
// x   x    (i-2,j-1), (i+2,j-1)
//   o      (i,j)
// x   x    (i-2,j+1), (i+2,j+1)
//  x x     (i-1,j+2), (i+1,j+2)

int dir[8][2] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1},
    {-2, 1}, {2, 1}, {-1, 2}, {1, 2}
};
int vis[8][8];
int dis[8][8];

void bfs(int i, int j, int i_end, int j_end)
{
    queue<pair<int, int>> q;
    pair<int, int> root(i, j);
    vis[root.i][root.j] = 1;
    q.push(root);
    while (!q.empty()) {
        int i_cur = q.front().i;
        int j_cur = q.front().j;
        q.pop();
        if (i_cur == i_end && j_cur == j_end) {
            return;
        }
        for (int x = 0; x < 8; x++) {
            int i_next = i_cur + dir[x][0];
            int j_next = j_cur + dir[x][1];
            if (i_next < 0 || i_next >= 8 || j_next < 0 || j_next >= 8 ||
                vis[i_next][j_next])
                continue;
            dis[i_next][j_next] = dis[i_cur][j_cur] + 1;
            vis[i_next][j_next] = 1;
            pair<int, int> next(i_next, j_next);
            q.push(next);
        }
    }
}

int main()
{
    string p1, p2;
    while (cin >> p1 >> p2) {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        int i = p1[0] - 'a';
        int j = p1[1] - '1';
        int i_end = p2[0] - 'a';
        int j_end = p2[1] - '1';
        bfs(i, j, i_end, j_end);
        printf("To get from %s to %s takes %d knight moves.\n",
               p1.c_str(), p2.c_str(), dis[i_end][j_end]);
    }
    return 0;
}
