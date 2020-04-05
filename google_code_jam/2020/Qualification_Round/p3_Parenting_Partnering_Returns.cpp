#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cin >> n;
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < n; i++) {
            int s, e;
            cin >> s >> e;
            v.push_back(make_pair(i, make_pair(s, e)));
        }
        sort(v.begin(), v.end(), [](auto a, auto b) {
            auto aa = a.second;
            auto bb = b.second;
            if (aa.first == bb.first) {
                return aa.second < bb.second;
            } else {
                return aa.first < bb.first;
            }
        });
        vector<int> C{0};
        vector<int> J{0};
        string out = "";
        char sche[n+1] = {0};
        for (int i = 0; i < n; i++) {
            int idx = v[i].first;
            int cur_start = v[i].second.first;
            int cur_end = v[i].second.second;
            if (cur_start >= C.back()) {
                C.push_back(cur_end);
                sche[idx] = 'C';
            } else if (cur_start >= J.back()) {
                J.push_back(cur_end);
                sche[idx] = 'J';
            } else {
                out = "IMPOSSIBLE";
                goto output;
            }
        }
        out = string(sche);
        output:
        cout << "Case #" << tt<< ": " << out << endl;
    }
    return 0;
}
