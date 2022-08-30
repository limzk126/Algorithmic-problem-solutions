/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> inDeg(n, 0);

        for (auto edge : edges)
        {
            inDeg[edge[0]]++;
            inDeg[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (inDeg[i] == 1)
            {
                --inDeg[i];
                q.push(i);
            }
        }

        int cnt = n;
        while (cnt > 2)
        {
            int sz = q.size();
            cnt -= sz;
            while (sz--)
            {
                int cur = q.front();
                q.pop();
                for (auto nb : edges[cur])
                {
                    if (--inDeg[nb] == 1)
                    {
                        q.push(nb);
                    }
                }
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end
