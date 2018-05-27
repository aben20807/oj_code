class Solution
{
public:
    bool check1to9(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8,
                   int n9)
    {
        map<int, bool> exist;
        exist[n1] = true;
        exist[n2] = true;
        exist[n3] = true;
        exist[n4] = true;
        exist[n5] = true;
        exist[n6] = true;
        exist[n7] = true;
        exist[n8] = true;
        exist[n9] = true;
        for (int i = 1; i <= 9; i++) {
            if (exist.find(i) == exist.end())
                return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int ans = 0;
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[0].size() - 1; j++) {
                if (grid[i][j] != 5 ||
                    !check1to9(grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1],
                               grid[i][j - 1], grid[i][j], grid[i][j + 1], grid[i + 1][j - 1], grid[i + 1][j],
                               grid[i + 1][j + 1]))
                    continue;
                else {
                    if ((grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] == 15) &&
                        (grid[i][j - 1] + grid[i][j] + grid[i][j + 1] == 15) &&
                        (grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1] == 15) &&
                        (grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1] == 15) &&
                        (grid[i - 1][j] + grid[i][j] + grid[i + 1][j] == 15) &&
                        (grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1] == 15) &&
                        (grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1] == 15) &&
                        (grid[i - 1][j + 1] + grid[i][j] + grid[i + 1][j - 1] == 15)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
