// 把拿到的物種存到 map 中
// 注意空行間隔

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        map<string, double> spn;
        double sum = 0;
        while (getline(cin, s)) {
            if (s.length() == 0)
                break;
            spn[s]++;
            sum++;
        }
        for (auto it : spn) {
            printf("%s %.4lf\n", it.first.c_str(), it.second * 100 / sum);
        }
        if (t)
            printf("\n");
    }
    return 0;
}
