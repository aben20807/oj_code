//  利用 Floyd 找 APSP
// 注意不是真的找最短路徑，而是路徑中最大分貝代表此路徑的分貝
// 注意每個 case 用換行分隔

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define INF 1e9

int dis[110][110];

int main()
{
    int c, s, q, casecnt = 1;
    while (scanf("%d%d%d", &c, &s, &q)) {
        if (c == 0 && s == 0 && q == 0)
            break;
        /* init */
        for (int i = 1; i <= c; i++) {
            for (int j = 1; j <= c; j++) {
                if (i == j)
                    dis[i][j] = 0;
                else {
                    dis[i][j] = INF;
                    dis[j][i] = INF;
                }
            }
        }
        for (int i = 0; i < s; i++) {
            int c1, c2, d;
            scanf("%d%d%d", &c1, &c2, &d);
            dis[c1][c2] = d;
            dis[c2][c1] = d;
        }
        /* Floyd */
        for (int k = 1; k <= c; k++) {
            for (int i = 1; i <= c; i++) {
                for (int j = 1; j <= c; j++) {
                    if (dis[i][j] > max(dis[i][k], dis[k][j]))
                        dis[i][j] = max(dis[i][k], dis[k][j]);
                }
            }
        }
        /* query */
        if (casecnt > 1)
            printf("\n");
        printf("Case #%d\n", casecnt++);
        for (int i = 0; i < q; i++) {
            int c1, c2;
            scanf("%d%d", &c1, &c2);
            if (dis[c1][c2] == INF) {
                printf("no path\n");
            } else {
                printf("%d\n", dis[c1][c2]);
            }
        }
    }
    return 0;
}
