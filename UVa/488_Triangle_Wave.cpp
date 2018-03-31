// 開頭有資料數，只有一個所以不須判斷EOF
// 注意每個波動之間都要有空行但是最後沒有空行
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    bool first1 = true;
    scanf("%d", &n);
    while (n--) {
        int a, f;
        scanf("%d%d", &a, &f);
        if (!first1) {
            printf("\n");
        }
        first1 = false;
        bool first2 = true;
        for (int i = 0; i < f; i++) {
            if (!first2) {
                printf("\n");
            }
            first2 = false;
            for (int j = 1; j < a; j++) {
                for (int k = 0; k < j; k++) {
                    printf("%d", j);
                }
                printf("\n");
            }
            for (int j = a; j >= 1; j--) {
                for (int k = j; k > 0; k--) {
                    printf("%d", j);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
