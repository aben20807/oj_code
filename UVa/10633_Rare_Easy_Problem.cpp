// 題目要你找出全部並排序是騙人的
// 這題最多就2個解(9的倍數)，若非9的倍數就只會有一個解，所以不用迴圈找解
// 可以從題目推出公式
// 給 N - M 求出 N，其中 M = N/10
// 則 N - N/10 = N*9/10 = 輸入的數字，所以 N = 輸入的數字*10/9 (注意要先乘)
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    unsigned long long a;
    while (scanf("%lld", &a) && a) {
        if (a % 9 == 0) {
            printf("%lld %lld\n", a * 10 / 9 - 1, a * 10 / 9);
        } else {
            printf("%lld\n", a * 10 / 9);
        }
    }
    return 0;
}
