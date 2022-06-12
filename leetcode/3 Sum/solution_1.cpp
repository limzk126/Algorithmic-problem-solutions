class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (!nums.size()) return res;
        sort(nums.begin(), nums.end());
        
        int i = 0;
        while (i < (int)size(nums) - 2) {
            int lo = i + 1;
            int hi = nums.size() - 1;
            
            while (lo < hi) {
                if (nums[lo] + nums[hi] < -nums[i]) {
                    ++lo;
                } else if (nums[lo] + nums[hi] > -nums[i]) {
                    --hi;
                } else {
                    res.push_back({nums[lo], nums[hi], nums[i]});
                    int curLo = nums[lo];
                    while (lo < nums.size() && nums[lo] == curLo) {
                        ++lo;
                    }
                    int curHi = nums[hi];
                    while (hi >= 0 && nums[hi] == curHi) {
                        --hi;
                    }
                }
            }
            
            int cur = nums[i];
            while (i < nums.size() && cur == nums[i]) {
                ++i;
            }
        }
        
        return res;
    }
};

/*
 * Sorted, closing two pointer approach.
 */