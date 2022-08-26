/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int cur = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (cur > intervals[i][0])
            {
                res++;
                if (intervals[i][1] <= cur)
                    cur = intervals[i][1];
            }
            else
            {
                cur = intervals[i][1];
            }
        }
        return res;
    }
};
// @lc code=end
