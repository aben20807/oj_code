#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        while (n--) {
            int l, u;
            scanf("%d%d", &l, &u);
            int maxnum = 0, index = 0;
            for (int i = l; i <= u; i++) {
                map<int, int> num;
                int tmp = i;
                for (int j = 2; j <= sqrt(tmp); j++) {
                    if (tmp % j == 0) {
                        num[j]++;
                        tmp /= j;
                        j--;
                    }
                }
                num[tmp]++;
                int divisors = 1;
                for (map<int, int>::iterator it = num.begin(); it != num.end(); ++it) {
                    if (it->first != 1)
                        divisors *= (it->second + 1);
                }
                if (maxnum < divisors) {
                    maxnum = divisors;
                    index = i;
                }
            }
            printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, index,
                   maxnum);
        }
    }
    return 0;
}
