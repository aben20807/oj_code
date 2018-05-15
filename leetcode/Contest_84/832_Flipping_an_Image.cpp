class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
    {
        vector<vector<int>> ret;
        for (auto a : A) {
            vector<int> newa(a.rbegin(), a.rend());
            for (int i = 0; i < newa.size(); i++) {
                newa[i] = !newa[i];
            }
            ret.push_back(newa);
        }
        return ret;
    }
};
