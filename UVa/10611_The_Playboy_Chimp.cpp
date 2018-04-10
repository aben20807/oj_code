// BS
// 注意不能和目前的猴子等高

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        vector<int> chimp;
        int tmp;
        while (n--) {
            scanf("%d", &tmp);
            chimp.push_back(tmp);
        }
        int q;
        scanf("%d", &q);
        vector<int> query;
        while (q--) {
            scanf("%d", &tmp);
            query.push_back(tmp);
        }
        for (int i : query) {
            auto it = lower_bound(chimp.begin(), chimp.end(), i);
            auto itn = it, itp = it;
            bool lb = false, ge = false;
            while (*itn == i) {
                itn++;
                if (itn >= chimp.end()) {
                    ge = true;
                    break;
                }
            }
            while (*itp == i || *itp == *itn) {
                itp--;
                if (itp < chimp.begin()) {
                    lb = true;
                    break;
                }
            }
            if (lb) {
                printf("X %d\n", *itn);
            } else if (ge) {
                printf("%d X\n", *itp);
            } else {
                printf("%d %d\n", *(itp), *(itn));
            }
        }
    }
    return 0;
}
