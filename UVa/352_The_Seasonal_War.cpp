#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
char m[26][26];
int vis[26][26];
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1}
};

void dfs(int i, int j, int& area)
{
    if (vis[i][j] == 0 && m[i][j] == '1') {
        vis[i][j] = 1;
        area++;
    } else {
        return;
    }
    for (int x = 0; x < 8; x++) {
        int i_next = i + dir[x][0];
        int j_next = j + dir[x][1];
        if (i_next < 0 || i_next >= n || j_next < 0 || j_next >= n)
            continue;
        if (m[i_next][j_next] == '1')
            dfs(i_next, j_next, area);
    }
}

int main()
{
    int casecnt = 1;
    while (scanf("%d", &n) != EOF) {
        memset(m, 0, sizeof(m));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            scanf("%s", m[i]);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int area = 0;
                dfs(i, j, area);
                // printf("%d", area);
                if (area > 0)
                    count++;
            }
        }
        printf("Image number %d contains %d war eagles.\n", casecnt++, count);
    }
    return 0;
}
