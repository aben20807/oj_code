#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int t, n, tmp;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cin >> n;
        unordered_set<int> r;
        unordered_set<int> c[n];
        int rr = 0;
        int cc = 0;
        int kk = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> tmp;
                r.insert(tmp);
                c[j].insert(tmp);
                if (i == j) {
                    kk += tmp;
                }
            }
            if (r.size() < n) {
                rr++;
            }
            r.clear();
        }
        for (int i = 0; i < n ; i++) {
            if (c[i].size() < n) {
                cc++;
            }
        }
        cout << "Case #" << tt<< ": " << kk << " " << rr << " " << cc << endl;
    }
    return 0;
}
