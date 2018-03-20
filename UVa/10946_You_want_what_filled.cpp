// Close to 352_The_Seasonal_War
// change '1' to map char and sort result
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define holename first
#define holesize second

int x, y;
char m[51][51];
int vis[51][51];
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void dfs(int i, int j, char c, int& holesize)
{
    vis[i][j] = 1;
    holesize++;
    for (int index = 0; index < 4; index++) {
        int i_next = i + dir[index][0];
        int j_next = j + dir[index][1];
        if (i_next < 0 || i_next >= x || j_next < 0 || j_next >= y)
            continue;
        if (!vis[i_next][j_next] && m[i_next][j_next] == c)
            dfs(i_next, j_next, c, holesize);
    }
    return;
}

bool cmp(const pair<char, int>& hole1, const pair<char, int>& hole2)
{
    if (hole1.holesize != hole2.holesize)
        return hole1.holesize > hole2.holesize;
    else
        return hole1.holename < hole2.holename;
}

int main()
{
    int casecnt = 1;
    while (scanf("%d%d", &x, &y)) {
        if (x == 0 && y == 0)
            break;
        memset(m, 0, sizeof(m));
        memset(vis, 0, sizeof(vis));
        vector<pair<char, int>> hole;
        for (int i = 0; i < x; i++) {
            scanf("%s", m[i]);
        }
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (m[i][j] == '.' || vis[i][j]) {
                    // printf("%d", 0);
                    continue;
                }
                int holesize = 0;
                dfs(i, j, m[i][j], holesize);
                // printf("%d", holesize);
                if (holesize > 0) {
                    hole.push_back(make_pair(m[i][j], holesize));
                }
            }
            // printf("\n");
        }
        printf("Problem %d:\n", casecnt++);
        sort(hole.begin(), hole.end(), cmp);
        for (int i = 0; i < (int)hole.size(); i++) {
            printf("%c %d\n", hole[i].holename, hole[i].holesize);
        }
    }
    return 0;
}
