#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

map<int, vector<int> > edge;
int llink[105], rlink[105];
bool used[105];

bool dfs(int now)
{
    for (int i = 0; i < (int)edge[now].size(); i++) {
        int nxt = edge[now][i];
        if (!used[nxt]) {
            used[nxt] = true;
            if (rlink[nxt] == -1 || dfs(rlink[nxt])) {
                llink[now] = nxt;
                rlink[nxt] = now;
                return true;
            }
        }
    }
    return false;
}

int bipartite(int nl, int nr)
{
    int ans = 0;
    memset(llink, -1, (nl) * sizeof(int));
    memset(rlink, -1, (nr) * sizeof(int));
    for (int i = 0; i < nl; i++) {
        memset(used, false, (nr) * sizeof(bool));
        if (dfs(i))
            ans++;
    }
    return ans;
}

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        edge.clear();
        int m, k;
        scanf("%d%d", &m, &k);
        for (int i = 0, ii, x, y; i < k; i++) {
            scanf("%d%d%d", &ii, &x, &y);
            if (x == 0 || y == 0)
                continue;
            edge[x].push_back(y);
        }
        int ans = bipartite(n, m);
        printf("%d\n", ans);
    }
    return 0;
}
