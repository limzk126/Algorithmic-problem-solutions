/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size() - 1, n = heights[0].size() - 1;
        vector<int> dir = {0, 1, 0, -1, 0};

        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size()));

        queue<vector<int>> q;
        for (int i = 0; i < n; ++i)
        {
            q.push({0, i});
            visited[0][i] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            q.push({i, 0})
                visited[i][0] = 1;
        };
        while (!q.empty())
        {
            auto cur = q.front();
            int r = cur[0], c = cur[1];
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dir[i], nc = c + dir[i];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || heights[nr][nc] < heights[r][c] || visited[nr][nc])
                    continue;
                q.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            q.push({m, i});
            if (visited[m][i] == 1) res.push_back({m, i});
            visited[m][i] = 2;
        }
        for (int i = 0; i < m - 1; ++i) {
            q.push({i, n});
            if (visited[i][n] == 1) res.push_back({i, n});
            visited[i][n] = 2;
        }
        while (!q.empty())
        {
            auto cur = q.front();
            int r = cur[0], c = cur[1];
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dir[i], nc = c + dir[i];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || heights[nr][nc] < heights[r][c] || visited[nr][nc])
                    continue;
                q.push({nr, nc});
                if (visited[nr][nc] == 1) res.push_back({nr, nc});
                visited[nr][nc] = 2;
            }
        }
    }
};
// @lc code=end
