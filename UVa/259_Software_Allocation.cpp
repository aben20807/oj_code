// 把得到的 app 與它後面的電腦建立 edge，需要建立 app 個數次
// e.g. A2 012; 建立 edge 0-0, 0-1, 0-2, 1-0, 1-1, 1-2 (左邊為 app 右邊為電腦)
// 而因為 app 因為不只一個所以會有不同編號(如上例左邊的 0, 1)
// 因此要建立 0, 1 是 A 的 map(app_name) 方便印出答案
// 演算法就使用匹配即可
// 注意 使用 getline 最後一筆測資會讀不到換行
// 所以跳出迴圈後再求一次最後一筆的答案

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

map<int, vector<int>> edge;
map<int, char> app_name;
int app_num = 0;
int llink[30], rlink[30];
bool used[30];

bool dfs(int now)
{
    for (int i = 0; i < (int)edge[now].size(); i++) {
        int nxt = edge[now][i];
        if (!used[nxt]) {
            used[nxt] = true;
            if (rlink[nxt] == -1 || dfs(rlink[nxt])) {
                llink[now] = nxt;
                rlink[nxt] = now;
                return true;
            }
        }
    }
    return false;
}

int bipartite(int nl, int nr)
{
    int ans = 0;
    memset(llink, -1, (nl) * sizeof(int));
    memset(rlink, -1, (nr) * sizeof(int));
    for (int i = 0; i < nl; i++) {
        memset(used, false, (nr) * sizeof(bool));
        if (dfs(i))
            ans++;
    }
    return ans;
}

void print_ans()
{
    int ans = bipartite(app_num, 10);
    if (app_num - ans != 0) {
        printf("!\n");
    } else {
        for (int i = 0; i < 10; i++) {
            if (rlink[i] == -1) {
                printf("_");
            } else {
                printf("%c", app_name[rlink[i]]);
            }
        }
        printf("\n");
    }
}

int main()
{
    string s;
    while (getline(cin, s)) {
        if (s.length() == 0) {
            print_ans();
            app_num = 0;
            edge.clear();
            app_name.clear();
        } else {
            char app = s[0];
            int app_n = s[1] - '0';
            int computer_n = s.length() - 4;
            int computer[computer_n];
            for (int i = 0; i < computer_n; i++) {
                computer[i] = s[i + 3] - '0';
            }
            for (int i = 0; i < app_n; i++) {
                for (int j = 0; j < computer_n; j++) {
                    edge[app_num].push_back(computer[j]);
                }
                app_name[app_num++] = app;
            }
        }
    }
    print_ans();
    return 0;
}
