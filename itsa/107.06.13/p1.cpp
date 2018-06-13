#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a, b, c;
    while (n--) {
        int cnt = 0;
        scanf("%d %d %d", &a, &b, &c);
        if (a < 60) cnt++;
        if (b < 60) cnt++;
        if (c < 60) cnt++;
        if (a >= 60 && b >= 60 && c >= 60) {
            printf("P\n");
        } else if (cnt == 1 && a + b + c >= 220) {
            printf("P\n");
        } else if (cnt == 1 && a + b + c < 220) {
            printf("M\n");
        } else {
            if (a >= 80 || b >= 80 || c >= 80) {
                printf("M\n");
            } else {
                printf("F\n");
            }
        }
    }
}
