#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<string> v;
bool alp[11][26] = {0};
char d[11];
bool hasans;

bool bs(const vector<string>& sorted_vec, string key)
{
    int mid, left = 0 ;
    int right = sorted_vec.size();
    while (left < right) {
        mid = left + (right - left) / 2;
        if (key > sorted_vec[mid]) {
            left = mid + 1;
        } else if (key < sorted_vec[mid]) {
            right = mid;
        } else {
            return true;
        }
    }
    return false;
}

bool bt(int index, int l)
{
    if (index == l) {
        string tmp(d);
        int found = bs(v, tmp);
        if (found == false) {
            hasans = true;
            return true;
        }
    } else {
        if (hasans)
            return true;
        for (int i = 0; i < 26; i++) {
            if (hasans)
                return true;
            if (alp[index][i]) {
                alp[index][i] = false;
                d[index] = char(i + 'A');
                bt(index + 1, l);
                alp[index][i] = true;
            }
        }
        return false;
    }
}

int main()
{
    int t, casecnt = 1;
    scanf("%d", &t);
    while (t--) {
        v.clear();
        hasans = false;
        memset(alp, 0, sizeof(alp));
        memset(d, 0, sizeof(d));
        int n, l;
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
            for (int j = 0; j < l; j++) {
                alp[j][v[i][j] - 'A'] = true;
            }
        }
        sort(v.begin(), v.end());
        bt(0, l);
        printf("Case #%d: ", casecnt++);
        if (hasans) {
            printf("%s\n", d);
        } else {
            printf("-\n");
        }
    }
    return 0;
}
