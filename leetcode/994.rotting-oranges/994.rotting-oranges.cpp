/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        vector<int> dir{0, 1, 0, -1, 0};
        int time = 0;
        while (!q.empty())
        {
            time++;
            int sz = q.size();
            while (sz--)
            {
                auto p = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int nr = p.first + dir[i], nc = p.second + dir[i + 1];
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                        continue;
                    if (grid[nr][nc] != 1)
                        continue;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    if (--fresh== 0)
                        return time;
                }
            }
        }

        return fresh ? -1 : 0;
    }
};
// @lc code=end
