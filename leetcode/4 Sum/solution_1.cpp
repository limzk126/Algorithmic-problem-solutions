class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        if (nums.empty()) {
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        int n = size(nums);
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rem = target - nums[i] - nums[j];
                int start = j + 1, end = n - 1;
                
                while (start < end) {
                    int curr = nums[start] + nums[end];
                    if (curr < rem) {
                        start++;
                    } else if (curr > rem) {
                        end--;
                    } else {
                        vector<int> quad = {nums[i], nums[j], nums[start], nums[end]};
                        ans.push_back(quad);
                        while (start < n && nums[start] == quad[2]) start++;
                        while (end >= 0 && nums[end] == quad[3]) end--;
                    }
                }
                
                while (j + 1 < n && nums[j] == nums[j + 1]) j++;
            }
            
            while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        
        return ans;
    }
};

/*
 * Time: O(N^3)
 * Space: O(1)
 */