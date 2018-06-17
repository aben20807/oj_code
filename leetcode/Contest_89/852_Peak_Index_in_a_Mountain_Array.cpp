class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& A)
    {
        int last = A[0];
        for (int i = 1; i < (int)A.size(); i++) {
            if (last < A[i]) {
                last = A[i];
            } else {
                return i - 1;
            }
        }
    }
};
