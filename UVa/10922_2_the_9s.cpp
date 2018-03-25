#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    string n;
    while (cin >> n) {
        if (n.length() == 1 && n[0] == '0')
            break;
        cout << n;
        int sum = 0;
        for (int i = 0; i < (int)n.length(); i++) {
            sum += (n[i] - '0');
        }
        // printf("%d\n", sum);
        if (sum % 9 == 0) {
            printf(" is a multiple of 9 and has 9-degree ");
            int cnt = 1;
            while (sum > 9) {
                cnt++;
                int tmp = sum;
                // printf("sum: %d\n", sum);
                sum = 0;
                while (tmp > 0) {
                    sum += (tmp % 10);
                    tmp /= 10;
                }
            }
            printf("%d.\n", cnt);
        } else {
            printf(" is not a multiple of 9.\n");
        }
    }
    return 0;
}
