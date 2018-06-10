#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

map<int, vector<int> > edge;
int llink[1000], rlink[1000];
bool used[1000];

bool dfs(int now, int u, int v)
{
    for (int i = 0; i < (int)edge[now].size(); i++) {
        int nxt = edge[now][i];
        if (now == u && nxt == v)
            continue;
        if (!used[nxt]) {
            used[nxt] = true;
            if (rlink[nxt] == -1 || dfs(rlink[nxt], u, v)) {
                llink[now] = nxt;
                rlink[nxt] = now;
                return true;
            }
        }
    }
    return false;
}

int bipartite(int nl, int nr, int u, int v)
{
    int ans = 0;
    memset(llink, -1, (nl) * sizeof(int));
    memset(rlink, -1, (nr) * sizeof(int));
    for (int i = 0; i < nl; i++) {
        memset(used, false, (nr) * sizeof(bool));
        if (dfs(i, u, v))
            ans++;
    }
    return ans;
}


int main()
{
    int n, casecnt = 1;
    while (scanf("%d", &n) && n) {
        edge.clear();
        int Xmin[n], Xmax[n], Ymin[n], Ymax[n];
        for (int i = 0; i < n; i++)
            scanf("%d%d%d%d", &Xmin[i], &Xmax[i], &Ymin[i], &Ymax[i]);
        for (int i = 0, x, y; i < n; i++) {
            scanf("%d%d", &x, &y);
            for (int j = 0; j < n; j++) {
                if (Xmin[j] <= x && x <= Xmax[j] && Ymin[j] <= y && y <= Ymax[j]) {
                    edge[j].push_back(i);
                }
            }
        }
        int pair_num = bipartite(n, n, -1, -1);
        int ans[n];
        for (int i = 0; i < n; i++)
            ans[i] = llink[i];
        printf("Heap %d\n", casecnt++);
        bool has_ans = false;
        for (int i = 0; i < n; i++) {
            if (bipartite(n, n, i, ans[i]) < pair_num) {
                printf("%s(%c,%d)", (has_ans) ? " " : "", i + 'A', ans[i] + 1);
                has_ans = true;
            }
        }
        if (!has_ans)
            printf("none");
        printf("\n\n");
    }
    return 0;
}
