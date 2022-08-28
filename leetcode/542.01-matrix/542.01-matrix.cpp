/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution
{
public:

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 0) q.push({r, c});
                else mat[r][c] = -1;
            }
        }

        vector<int> dir = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int r = p.first, c = p.second;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i], nc = c + dir[i + 1];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || mat[nr][nc] != -1) continue;

                mat[nr][nc] = mat[r][c] + 1;
                q.push({nr, nc});
            } 
        }

        return mat;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
