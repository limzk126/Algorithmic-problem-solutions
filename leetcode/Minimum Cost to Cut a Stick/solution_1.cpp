class Solution {
    public:
        int minCost(int n, vector<int>& cuts) {
            cuts.insert(cuts.begin(), 0);
            cuts.push_back(n);
            sort(cuts.begin(), cuts.end());

            int nc = cuts.size();
            vector<vector<int>> dp(nc, vector<int>(nc, INT_MAX));
            for (int i = 0; i + 1 < nc; ++i) {
                dp[i][i + 1] = 0;
            }

            for (int i = 2; i < nc; ++i) {
                for (int j = 0; j + i < nc; ++j) {
                    for (int k = j + 1, start = j, end = j + i; k < end; ++k) {
                        dp[start][end] = min(dp[start][end], dp[start][k] + dp[k][end] + cuts[end] - cuts[start]);
                    }
                }
            }

            return dp[0][nc - 1];
        }
};
