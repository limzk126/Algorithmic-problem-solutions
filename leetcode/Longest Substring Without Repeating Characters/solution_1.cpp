class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        
        int longest = 0;
        int cummulative = 0;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (um.count(s[i]) && um[s[i]] >= start) {
                cummulative = i - um[s[i]] - 1;
                start = um[s[i]] + 1;
            }
            
            cummulative += 1;
            um[s[i]] = i;
            longest = max(longest, cummulative);
        }
        
        
        return longest;
    }
};