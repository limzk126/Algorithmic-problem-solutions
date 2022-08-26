/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_set<int> s;
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (auto num : nums) {
            s.insert(num);
        }

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (s.find(i - j) != s.end()) {
                    dp[i] += dp[j];
                }
            }
        }

        return dp[target];
    }
};
// @lc code=end

