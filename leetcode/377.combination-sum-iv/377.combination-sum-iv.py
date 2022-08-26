#
# @lc app=leetcode id=377 lang=python3
#
# [377] Combination Sum IV
#

# @lc code=start
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in range(target + 1):
            for x in nums:
                if i >= x:
                    dp[i] = dp[i] + dp[i - x]
        return dp[target] 
# @lc code=end

