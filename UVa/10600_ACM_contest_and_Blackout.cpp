// 第一個 MST 就使用 Kruskal
// 第二小的 MST 就用枚舉
// 在第一次先存取出現在 MST 的 edge 到 graph
// 枚舉時跳過該次枚舉中出現在 graph 的 edge，第 i 次就跳過第 i 個 MST 中的 edge
// 一樣每次都跑 Kruskal 並存下長度，然後跟目前最小比較
// 記得加滿 n-1 邊才算是一個 MST

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
    int a;
    int b;
    int len;
} e[800 * 800];

int sset[800];

bool cmp(edge A, edge B)
{
    return A.len < B.len;
}

int Find_Root(int x)
{
    if (x == sset[x])
        return x;
    return sset[x] = Find_Root(sset[x]);
}

bool is_connect(edge A)
{
    int x = Find_Root(A.a);
    int y = Find_Root(A.b);
    return x == y;
}

bool Union(edge A)
{
    int x = Find_Root(A.a);
    int y = Find_Root(A.b);
    if (x != y) {
        sset[x] = y;
        return true;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].len);
        }
        /* init */
        for (int i = 0; i <= n; i++) {
            sset[i] = i;
        }
        /* Kruskal */
        sort(e, e + m, cmp);
        int ans = 0;
        vector<struct edge> graph;
        for (int i = 0; i < m; i++) {
            if (Union(e[i])) {
                ans += e[i].len;
                graph.push_back(e[i]);
            }
        }
        printf("%d ", ans);
        int ans2 = 1e9;
        for (int i = 0; i < (int)graph.size(); i++) {
            struct edge cur = graph[i];
            int tmpans = 0, cnt = 0;
            for (int i = 0; i <= n; i++) {
                sset[i] = i;
            }
            for (int j = 0; j < m; j++) {
                if (e[j].a == cur.a && e[j].b == cur.b && e[j].len == cur.len)
                    continue;
                if (Union(e[j])) {
                    tmpans += e[j].len;
                    cnt++;
                }
                if (cnt == n - 1)
                    break;
            }
            if (cnt == n - 1)
                ans2 = min(ans2, tmpans);
        }
        printf("%d\n", ans2);
    }
    return 0;
}
