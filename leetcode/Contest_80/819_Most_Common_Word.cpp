class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string>& banned)
    {
        for (char &c : paragraph) {
            if (isalpha(c) || isdigit(c)) {
                c = tolower(c);
            } else {
                c = ' ';
            }
        }
        map<string, int> freq;
        stringstream ss(paragraph);
        string tmps;
        while (ss >> tmps) {
            bool isban = false;
            for (string s : banned) {
                if (s == tmps) {
                    isban = true;
                    break;
                }
            }
            if (!isban) {
                freq[tmps]++;
                // cout << tmps << freq[tmps] << endl;
            }
        }
        auto it = freq.begin();
        string ans = it->first;
        int maxfreq = it->second;
        while (it != freq.end()) {
            if (maxfreq < it->second) {
                maxfreq = it->second;
                ans = it->first;
            }
            it++;
        }
        return ans;
    }
};
