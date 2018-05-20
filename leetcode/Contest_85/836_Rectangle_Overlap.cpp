class Solution
{
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        long long r1l = rec1[0];
        long long r1r = rec1[2];
        long long r2l = rec2[0];
        long long r2r = rec2[2];

        long long r1d = rec1[1];
        long long r1u = rec1[3];
        long long r2d = rec2[1];
        long long r2u = rec2[3];

        long long au = min(r1u, r2u);
        long long ad = max(r1d, r2d);
        long long ar = min(r1r, r2r);
        long long al = max(r1l, r2l);
        return ((au - ad) > 0) && ((ar - al) > 0) && ((au - ad) * (ar - al)) > 0;
    }
};
