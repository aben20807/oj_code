#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int snum;

long long countdamage(string p)
{
    long long beam = 1;
    long long sum = 0;
    for (int i = 0; i < (int)p.length(); i++) {
        switch (p[i]) {
        case 'C':
            beam *= 2;
            break;
        case 'S':
            sum += beam;
            snum++;
            break;
        }
    }
    return sum;
}

int main()
{
    int t;
    int casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        snum = 0;
        long long d;
        scanf("%lld", &d);
        string p;
        cin >> p;
        // printf("%lld\n", d);
        // printf("%s ", p.c_str());
        long long sum = countdamage(p);
        // printf("%lld\n", sum);
        printf("Case #%d: ", casecnt++);
        if (snum > d) {
            printf("IMPOSSIBLE\n");
        } else if (sum <= d) {
            printf("%d\n", 0);
        } else {
            long long hack = 0;
            long long lastsum = sum;
            bool impossible = false;
            while (sum > d) {
                for (int i = p.length() - 1; i > 0; i--) {
                    if (p[i] == 'S' && p[i - 1] == 'C') {
                        swap(p[i], p[i - 1]);
                        sum = countdamage(p);
                        hack++;
                        break;
                    }
                }
                if (lastsum == sum) {
                    impossible = true;
                    break;
                }
            }
            if (impossible) {
                printf("IMPOSSIBLE\n");
            } else {
                printf("%lld\n", hack);
            }
        }
    }
    return 0;
}
