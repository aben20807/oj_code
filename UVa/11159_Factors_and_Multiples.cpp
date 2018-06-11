#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

int llink[105], rlink[105];
bool used[105];
map<int, vector<int>> edge;

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
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        edge.clear();
        int n, m;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        int b[m];
        for (int i = 0; i < m; i++)
            scanf("%d", &b[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] && b[j] % a[i] == 0)
                    edge[i].push_back(j);
                else if (!b[j])
                    edge[i].push_back(j);
            }
        }
        int ans = bipartite(n, m);
        printf("Case %d: %d\n", casecnt++, ans);
    }
    return 0;
}
