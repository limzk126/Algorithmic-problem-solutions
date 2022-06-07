class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> om;
        for (int i = 0; i < size(nums); ++i) {
            if (om.find(target - nums[i]) != om.end()) {
                ans.push_back(om[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            
            om[nums[i]] = i;
        }
        
        return ans;
    }
};