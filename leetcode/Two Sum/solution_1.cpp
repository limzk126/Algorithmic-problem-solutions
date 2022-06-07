class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> om;
        for (int i = 0; i < size(nums); ++i) {
            if (om.find(target - nums[i]) != om.end()) {
                return {om[target - nums[i]], i};
            }
            
            om[nums[i]] = i;
        }
        
        return {};
    }
};