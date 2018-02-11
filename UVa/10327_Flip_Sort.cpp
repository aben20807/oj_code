#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int flip = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    flip++;
                }
            }
        }
        // for (int i = 0; i < n; i++){
        // printf("%d ", a[i]);
        // }
        printf("Minimum exchange operations : %d\n", flip);
    }
    return 0;
}
