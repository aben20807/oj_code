#include <iostream>
#include <vector>
using namespace std;

inline bool ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

int main()
{
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        vector <string> v(N);
        string longger = "";
        string ans = "";
        for (int i = 0; i < N; i++) {
            cin >> v[i];
            if (v[i].length() > longger.length()) {
                longger = v[i];
            }
        }
        for (int i = 0; i < N; i++) {
            if (!ends_with(longger, v[i].substr(1))) {
                ans = "*";
                goto output;
            }
        }
        ans = longger.substr(1);
        output:
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
