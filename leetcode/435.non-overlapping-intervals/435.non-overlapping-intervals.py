#
# @lc app=leetcode id=435 lang=python3
#
# [435] Non-overlapping Intervals
#

# @lc code=start
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[0])
        n = len(intervals) 
        cur = intervals[0][1]
        res = 0
        for i in range(1, n):
            if intervals[i][0] < cur:
                res = res + 1
                if intervals[i][1] < cur:
                    cur = intervals[i][1]
            else:
                cur = intervals[i][1]
        
        return res
# @lc code=end

