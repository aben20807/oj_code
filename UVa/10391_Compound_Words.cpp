// 利用 map 的 hash 特性
// 記得用 find() 去找，不要使用 dic[] 判斷是否為 true，避免 map 加入其他字串

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

int main()
{
    map <string, bool> dic;
    string s;
    while (cin >> s) {
        dic[s] = true;
    }
    for (auto it : dic) {
        int len = it.first.length();
        for (int i = 1; i < len; i++) {
            string t1 = it.first.substr(0, i);
            if (dic.find(t1) == dic.end()) {
                continue;
            }
            string t2 = it.first.substr(i, len - i);
            if (dic.find(t2) == dic.end()) {
                continue;
            } else {
                printf("%s\n", it.first.c_str());
                break;
            }
        }
    }
    return 0;
}
