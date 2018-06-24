// tree 用 map 存會 TLE, 改用二維 vector
// 測資只有一個所以不用 test EOF, 陣列也不用 memset
// 注意 scanf 字元時要加空格在後方

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int bit[100010], t_start[100010], t_end[100010];
bool picked[100010];
int N;
int dfn;
vector <vector<int> > tree(100010);

void dfs(int index)
{
    t_start[index] = dfn++;
    for (int i = 0; i < (int)tree[index].size(); i++)
        dfs(tree[index][i]);
    t_end[index] = dfn;
}

int lowbit(int x)
{
    return x & (-x);
}

int get_sum(int index)
{
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= lowbit(index);
    }
    return sum;
}

void change(int index, int delta)
{
    for (int i = index; i <= N; i += lowbit(i))
        bit[i] += delta;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0, u, v; i < N - 1; i++) {
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
    }
    dfn = 1;
    dfs(1);
    for (int i = 1; i <= N; i++) {
        change(t_start[i], 1);
        picked[i] = false;
    }
    int m;
    scanf("%d ", &m);
    for (int i = 0, x; i < m; i++) {
        char cmd;
        scanf("%c%d ", &cmd, &x);
        switch (cmd) {
        case 'C':
            if (picked[x]) {
                picked[x] = false;
                change(t_start[x], 1);
            } else {
                picked[x] = true;
                change(t_start[x], -1);
            }
            break;
        case 'Q':
            printf("%d\n", get_sum(t_end[x] - 1) - get_sum(t_start[x] - 1));
            break;
        }
    }
    return 0;
}
