#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// algorithm ref: https://www.youtube.com/watch?v=OlpC2d1Odrs

inline bool end_with(std::string const & value, std::string const & suffix)
{
    if (suffix.size() > value.size()) return false;
    return std::equal(suffix.rbegin(), suffix.rend(), value.rbegin());
}

inline bool start_with(std::string const & value, std::string const & prefix)
{
    if (prefix.size() > value.size()) return false;
    return std::equal(prefix.begin(), prefix.end(), value.begin());
}

int main()
{
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        vector <string> interfix(N);
        vector <string> prefix(N);
        vector <string> suffix(N);
        string longger_prefix = "";
        string longger_suffix = "";
        for (int i = 0; i < N; i++) {
            string tmp;
            cin >> tmp;
            auto first_asterisk = tmp.find_first_of("*");
            auto last_asterisk = tmp.find_last_of("*");
            prefix[i] = tmp.substr(0, first_asterisk);
            suffix[i] = tmp.substr(last_asterisk+1);
            interfix[i] = tmp.substr(first_asterisk, last_asterisk);
            // delete all * in interfix. Ref: https://stackoverflow.com/a/20326454
            interfix[i].erase(remove(interfix[i].begin(), interfix[i].end(), '*'), interfix[i].end());

            if (prefix[i].length() > longger_prefix.length()) {
                longger_prefix = prefix[i];
            }
            if (suffix[i].length() > longger_suffix.length()) {
                longger_suffix = suffix[i];
            }
            // cout << "p" << prefix[i] << endl;
            // cout << "s" << suffix[i] << endl;
            // cout << "i" << interfix[i] << endl;
        }
        string ans = longger_prefix;
        for (int i = 0; i < N; i++) {
            if (!start_with(longger_prefix, prefix[i])) {
                ans = "*";
                goto output;
            }
            if (!end_with(longger_suffix, suffix[i])) {
                ans = "*";
                goto output;
            }
            ans += interfix[i];
        }
        ans += longger_suffix;
        // cout << longger_prefix << "," << longger_suffix << endl;
        output:
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
