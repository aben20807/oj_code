// 找出所有長度為 n 的子字串利用 map 記錄個數

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        string s;
        cin >> s;
        map<string, int> Map;
        for (int i = 0; i <= (int)s.size() - n; i++) {
            string tmp = s.substr(i, n);
            Map[tmp]++;
        }
        int mmax = 0;
        string ans;
        for (auto m : Map) {
            if (m.second > mmax) {
                mmax = m.second;
                ans = m.first;
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}
