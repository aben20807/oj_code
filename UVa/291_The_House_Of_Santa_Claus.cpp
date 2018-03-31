#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int ans[9];
map<int, vector<int>> adj;
int vis[6][6];

void bt(int point, int step)
{
    if (step == 9) {
        for (int &a : ans)
            printf("%d", a);
        printf("\n");
    } else {
        for (int nxt : adj[point]) {
            if (vis[point][nxt] == 0 && vis[nxt][point] == 0) {
                vis[point][nxt] = 1, vis[nxt][point] = 1;
                ans[step] = nxt;
                bt(nxt, step + 1);
                vis[point][nxt] = 0, vis[nxt][point] = 0;
            }
        }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    adj.clear();
    adj[1] = {2, 3, 5};
    adj[2] = {1, 3, 5};
    adj[3] = {1, 2, 4, 5};
    adj[4] = {3, 5};
    adj[5] = {1, 2, 3, 4};
    ans[0] = 1;
    bt(1, 1);
    return 0;
}
