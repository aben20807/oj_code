class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> a(S.length());
        fill(a.begin(), a.end(), -1);
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == C) {
                a[i] = 0;
                int count = 1;
                for (int j = i - 1; a[j] != 0 && j >= 0; j--) {
                    a[j] = count++;
                }
            }
        }
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == C) {
                int count = 1;
                for (int j = i + 1; (a[j] == -1 || count < a[j]) && j < S.length(); j++) {
                    a[j] = count++;
                }
            }
        }
        return a;
    }
};
