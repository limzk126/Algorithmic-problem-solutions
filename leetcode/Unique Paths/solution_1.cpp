class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        int leftPtr = 0;
        for (int i = 1; i < m; ++i) {
            leftPtr = 0;
            for (int i = 0; i < n; ++i) {
                dp[i] = dp[i] + leftPtr;
                leftPtr = dp[i];
            }
        }
        
        return dp.back();
    }
};

/*
 * Time: O(n * m)
 * Space: O(m)
 * Simple dynamic programming, left-right and top-down approach.
 */