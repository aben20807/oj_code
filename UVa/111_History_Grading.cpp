#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

// int lcs()
// {
// }

int main()
{
    string tmps;
    int n;
    vector<int> c;
    while (getline(cin, tmps)) {
        if (tmps.length() > 0 && (int)tmps.find(" ") == -1) {
            // memset(c, 0, sizeof(c));
            c.clear();
            n = atoi(tmps.c_str());
            // printf("%d\n", n);
            for (int i = 0; i < n; i++) {
                int tmpn;
                scanf("%d", &tmpn);
                c.push_back(tmpn);
            }
            for (int i = 0; i < n; i++) {
                // printf("%d ", c[i]);
            }
            // printf("\n");
        } else if (tmps.length() > 0) {
            stringstream ss(tmps);
            vector<int> r;
            r.clear();
            int tmpn;
            while (ss >> tmpn) {
                // printf("%d ", tmpn);
                r.push_back(tmpn);
            }
            for (int i : c) {
                printf("%d ", i);
            }
            printf("\n");
            for (int i : r) {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
    return 0;
}
