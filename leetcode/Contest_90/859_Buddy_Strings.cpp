class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.length() != B.length())
            return false;
        int diff = 0;
        vector<char> diffa, diffb;
        for (int i = 0; i < (int)A.length(); i++) {
            if (A[i] != B[i]) {
                diff++;
                diffa.push_back(A[i]);
                diffb.push_back(B[i]);
            }
        }
        if (diff == 2 && diffa[0] == diffb[1] && diffa[1] == diffb[0]) {
            return true;
        } else if (diff == 0) {
            bool sameflag = false;
            for (int i = 1; i < (int)A.length(); i++) {
                for (int j = 0; j < i; j++) {
                    if (A[i] == A[j]) {
                        sameflag = true;
                        goto out;
                    }
                }
            }
out:
            if (sameflag)
                return true;
            else
                return false;
        } else {
            return false;
        }
    }
};
