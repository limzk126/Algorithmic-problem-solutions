class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int l = j - 1, u = i - 1;
                    int lv = l >= 0 ? grid[i][l] : INT_MAX;
                    int uv = u >= 0 ? grid[u][j] : INT_MAX;

                    if (lv == INT_MAX && uv == INT_MAX) continue;

                    grid[i][j] = min(lv, uv) + grid[i][j];
                }
            }

            return grid[n - 1][m - 1];
        }
};
