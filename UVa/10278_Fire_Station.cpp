#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;

#define INF 1e9

int f_pos[110];
int dis[510][510];

int main()
{
    int t;
    bool isfirst = true;
    scanf("%d", &t);
    while (t--) {
        int F, I;
        scanf("%d%d", &F, &I);
        for (int i = 0; i < F; i++) {
            scanf("%d", &f_pos[i]);
        }
        /* init */
        for (int i = 1; i <= I; i++) {
            for (int j = 1; j <= I; j++) {
                if (i == j)
                    dis[i][j] = 0;
                else {
                    dis[i][j] = INF;
                    dis[j][i] = INF;
                }
            }
        }
        string tmps;
        getline(cin, tmps);
        while (getline(cin, tmps)) {
            if (tmps.length() == 0)
                break;
            int a, b, d;
            stringstream ss(tmps);
            ss >> a >> b >> d;
            dis[a][b] = d;
            dis[b][a] = d;
            // printf("%d %d %d\n", a, b, d);
        }
        /* Floyd */
        for (int k = 1; k <= I; k++) {
            for (int i = 1; i <= I; i++) {
                for (int j = 1; j <= I; j++) {
                    if (dis[i][j] > dis[i][k] + dis[k][j])
                        dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
        int shortd[510];
        int maxshortd = 0;
        for (int i = 1; i <= I; i++) {
            shortd[i] = INF;
            for (int j = 0; j < F; j++) {
                if (shortd[i] > dis[i][f_pos[j]])
                    shortd[i] = dis[i][f_pos[j]];
            }
            if (maxshortd < shortd[i])
                maxshortd = shortd[i];
        }
        int ans = 1;
        for (int i = 1; i <= I; i++) {
            int new_length = 0;
            for (int j = 1; j <= I; j++) {
                int shorter = min(dis[i][j], shortd[j]);
                new_length = max(new_length, shorter);
            }
            if (new_length < maxshortd) {
                maxshortd = new_length;
                ans = i;
            }
        }
        if (isfirst)
            isfirst = false;
        else
            printf("\n");
        printf("%d\n", ans);
    }
    return 0;
}
