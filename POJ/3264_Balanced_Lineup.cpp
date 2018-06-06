#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int s[50010];

struct Node {
    int max_val;
    int min_val;
    Node *l, *r;
    void update(int update_val)
    {
        max_val = update_val;
        min_val = update_val;
    }
    void pull()
    {
        max_val = max(l->max_val, r->max_val);
        min_val = min(l->min_val, r->min_val);
    }
};

Node *build(int L, int R)
{
    Node *now = new Node();
    if (L == R) {
        now->update(s[L]);
        return now;
    }
    int mid = (L + R) >> 1;
    now->l = build(L, mid);
    now->r = build(mid + 1, R);
    now->pull();
    return now;
}

int query_max(Node *now, int L, int R, int x, int y)
{
    if (x > R || y < L)
        return -1e9;
    if (x <= L && y >= R)
        return now->max_val;
    int mid = (L + R) >> 1;
    return max(query_max(now->l, L, mid, x, y), query_max(now->r, mid + 1, R, x,
               y));
}

int query_min(Node *now, int L, int R, int x, int y)
{
    if (x > R || y < L)
        return 1e9;
    if (x <= L && y >= R)
        return now->min_val;
    int mid = (L + R) >> 1;
    return min(query_min(now->l, L, mid, x, y), query_min(now->r, mid + 1, R, x,
               y));
}

int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q)) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &s[i]);
        }
        Node *cow = build(1, n);
        while (q--) {
            int x, y;
            scanf("%d%d", &x, &y);
            int mmax = query_max(cow, 1, n, x, y);
            int mmin = query_min(cow, 1, n, x, y);
            printf("%d\n", mmax - mmin);
        }
    }
    return 0;
}
