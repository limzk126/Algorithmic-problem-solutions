class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_map<string, bool> mp;
            int n = s.size(); 
            int longestWord = INT_MIN;
            for (int i = 0; i < wordDict.size(); ++i) {
                mp[wordDict[i]] = true;
                longestWord = max(longestWord, (int)wordDict[i].size());
            }

            vector<bool> dp(n + 1, false);
            dp[0] = true; 

            for (int i = 1; i <= n; ++i) {
                for (int j = i - 1; j >= 0 && j >= max(i - longestWord, 0); --j) {
                    string word = s.substr(j, i - j);
                    if (mp.find(word) != mp.end()) {
                        if (!dp[j]) continue;
                        dp[i] = dp[j];
                        break;
                    }
                }
            }

            return dp[n];
        }
};
