#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
using namespace std;

int main()
{
    int ds;
    while (scanf("%d", &ds) != EOF) {
        while (ds--) {
            int m, n, p;
            scanf("%d%d%d", &m, &n, &p);
            map<string, queue<string>> adj;
            printf("%d, %d, %d\n", m, n, p);
            string warehouse[m];
            for (int i = 0; i < m; i++) {
                cin >> warehouse[i];
                printf("%s\n", warehouse[i].c_str());
            }
            for (int i = 0; i < n; i++) {
                string w1, w2;
                cin >> w1 >> w2;
                adj[w1].push(w2);
                adj[w2].push(w1);
                printf("%s - %s\n", w1.c_str(), w2.c_str());
            }
            for (int i = 0; i < p; i++) {
                int price;
                scanf("%d", &price);
                string from, to;
                cin >> from >> to;
                printf("%d: %s - %s\n", price, from.c_str(), to.c_str());
            }
        }
    }
    return 0;
}
