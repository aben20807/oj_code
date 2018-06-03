#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

const int S = 0, T = 27;
int flow[55][55];
int pre[55];
int bottle[55];
string prob[55][55];
int n;

bool bfs()
{
    memset(pre, -1, sizeof(pre));
    queue<int> q;
    q.push(S);
    pre[S] = S;
    bottle[S] = 1e9;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < T + 1 + n; i++) {
            if (flow[u][i] == 0 || pre[i] != -1)
                continue;
            pre[i] = u;
            bottle[i] = min(bottle[u], flow[u][i]);
            if (i == T) return true;
            q.push(i);
        }
    }
    return false;
}

void EdmondsKarp()
{
    while (bfs()) {
        int b = bottle[T];
        int v = T;
        while (pre[v] != v) {
            int u = pre[v];
            flow[u][v] -= b;
            flow[v][u] += b;
            v = u;
        }
    }
}

int main()
{
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        memset(flow, 0, sizeof(flow));
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            flow[S][i + T + 1] = 1;
            flow[i + 1][T] = 1;
        }
        for (int i = 0, ki; i < n; i++) {
            scanf("%d", &ki);
            while (ki--) {
                string tmps;
                cin >> tmps;
                tmps[0] = toupper(tmps[0]);
                for (int j = 1; j < (int)tmps.length(); j++)
                    tmps[j] = tolower(tmps[j]);
                int letter = tmps[0] - 'A' + 1;
                flow[i + T + 1][letter] = 1;
                prob[i + T + 1][letter] = tmps;
            }
        }
        EdmondsKarp();
        printf("Case #%d:\n", casecnt++);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                if (flow[j + T + 1][i] == 0 && flow[i][j + T + 1] != 0) {
                    cout << prob[j + T + 1][i] << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
