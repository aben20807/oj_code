class Solution
{
public:
    string toGoatLatin(string S)
    {
        stringstream ss(S), ans("");
        string tmps;
        int cnt = 0;
        while (ss >> tmps) {
            cnt++;
            string news;
            if (tmps[0] == 'a' ||
                tmps[0] == 'e' ||
                tmps[0] == 'i' ||
                tmps[0] == 'o' ||
                tmps[0] == 'u' ||
                tmps[0] == 'A' ||
                tmps[0] == 'E' ||
                tmps[0] == 'I' ||
                tmps[0] == 'O' ||
                tmps[0] == 'U'
               ) {
                news = tmps + "ma";
            } else {
                news = tmps.substr(1) + tmps[0] + "ma";
            }
            for (int i = 0; i < cnt; i++) {
                news += "a";
            }
            //cout  << news << " ";
            ans << news << " ";
        }
        string ret = ans.str();
        return ret.substr(0, ret.length() - 1);
    }
};
