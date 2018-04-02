#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, mid;
        scanf("%d%d", &a, &b);
        b++;
        int n;
        scanf("%d", &n);
        while (n--) {
            mid = (a + b) / 2;
            printf("%d\n", mid);
            string s;
            cin >> s;
            if (s == "CORRECT") {
                break;
            } else if (s == "TOO_BIG") {
                b = mid;
            } else if (s == "TOO_SMALL") {
                a = mid;
            } else {
                goto out;
            }
        }
    }
out:
    return 0;
}
