#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    vector<int> h2 = {2};
    vector<int> h3 = {3};
    vector<int> h5 = {5};
    vector<int> ha = {1};
    int cnt = 0;
    int n = 1500;
    while (cnt < n) {
        cnt++;
        int m2 = h2[0];
        int m3 = h3[0];
        int m5 = h5[0];
        int minnum;
        if (m2 <= m3 && m2 <= m5) {
            minnum = h2[0];
            if (m2 == m3) {
                h3.erase (h3.begin(), h3.begin() + 1);
            }
            if (m2 == m5) {
                h5.erase (h5.begin(), h5.begin() + 1);
            }
            h2.erase (h2.begin(), h2.begin() + 1);
        } else if (m3 <= m2 && m3 <= m5) {
            minnum = h3[0];
            if (m2 == m3) {
                h2.erase (h2.begin(), h2.begin() + 1);
            }
            if (m3 == m5) {
                h5.erase (h5.begin(), h5.begin() + 1);
            }
            h3.erase (h3.begin(), h3.begin() + 1);
        } else if (m5 <= m3 && m5 <= m2) {
            minnum = h5[0];
            if (m5 == m3) {
                h3.erase (h3.begin(), h3.begin() + 1);
            }
            if (m2 == m5) {
                h2.erase (h2.begin(), h2.begin() + 1);
            }
            h5.erase (h5.begin(), h5.begin() + 1);
        }
        ha.push_back(minnum);
        h2.push_back(minnum * 2);
        h3.push_back(minnum * 3);
        h5.push_back(minnum * 5);
    }
    printf("The 1500'th ugly number is %d.\n", ha[n - 1]);
    return 0;
}
