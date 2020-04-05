#include <iostream>
using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cin >> s;
        s.push_back('0');
        int len = s.length();
        string out;
        int cur, pre = 0, nxt = 0;;
        for (int i = 0; i < len-1; i++) {
            cur = s[i]-'0';
            nxt = s[i+1]-'0';
            for (int j = 0; j < cur-pre; j++) {
                out.push_back('(');
            }
            out.push_back(s[i]);
            for (int j = 0; j < cur-nxt; j++) {
                out.push_back(')');
            }
            pre = cur;
        }
        cout << "Case #" << tt << ": " << out << endl;
    }
    return 0;
}
