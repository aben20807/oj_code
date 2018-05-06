class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        S += char(S[S.length() - 1] - 1); // Add a tail different from last char
        char last = S[0];
        int start = 0;
        int gcnt = 1;
        vector<vector<int>> ans;
        for (int i = 1; i < S.length(); i++) {
            if (S[i] == last) {
                gcnt++;
            } else if (S[i] != last || i == S.length() - 1) {
                // cout << gcnt << endl;
                if (gcnt >= 3) {
                    // cout << start << i << endl;
                    vector<int> tmp;
                    tmp.push_back(start);
                    tmp.push_back(i - 1);
                    ans.push_back(tmp);
                }
                gcnt = 1;
                start = i;
            }
            last = S[i];
        }
        return ans;
    }
};
