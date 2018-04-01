#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        double d, mmin;
        scanf("%lf%d", &d, &n);
        bool isfirst = true;
        while (n--) {
            double ki, si;
            scanf("%lf%lf", &ki, &si);
            double hour = (d - ki) / si;
            double speed = (ki / hour) + si;
            if (isfirst) {
                mmin = speed;
                isfirst = false;
            }
            if (mmin > speed) {
                mmin = speed;
            }
        }
        printf("Case #%d: ", casecnt++);
        printf("%lf\n", mmin);
    }
    return 0;
}
