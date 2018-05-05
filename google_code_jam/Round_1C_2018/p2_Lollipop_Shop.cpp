#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

bool bs(const int *sorted_vec, int size, int key)
{
    int mid, left = 0 ;
    int right = size;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (key > sorted_vec[mid]) {
            left = mid + 1;
        } else if (key < sorted_vec[mid]) {
            right = mid;
        } else {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    srand(time(NULL));
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int nn = n;
        bool sell[n];
        memset(sell, 0, sizeof(sell));
        while (nn--) {
            int nf;
            scanf("%d", &nf);
            if (nf == 0) {
                printf("-1\n");
                fflush(stdout);
            } else {
                int fla[nf];
                for (int i = 0; i < nf; i++) {
                    scanf("%d", &fla[i]);
                }
                int tryy[n];
                memset(tryy, 0, sizeof(tryy));
                for (int i = 0; i < n; i++) {
                    int x = rand() % n;
                    if (tryy[x] == 1) {
                        i--;
                        continue;
                    }
                    // printf("x%d\n", x);
                    tryy[x] = 1;
                    bool f = bs(fla, nf, x);
                    // printf("f%d\n", f);
                    if (!sell[x] && f) {
                        printf("%d\n", x);
                        fflush(stdout);
                        sell[x] = true;
                        break;
                    }
                    if (i == n - 1) {
                        printf("-1\n");
                        fflush(stdout);
                    }
                }
            }
        }
    }
    return 0;
}
