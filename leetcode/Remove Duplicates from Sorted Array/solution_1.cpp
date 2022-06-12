class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        
        int availSlot = 1;
        int cur = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != cur) {
                nums[availSlot] = nums[i];
                ++availSlot;
                cur = nums[i];
            }
        }
        
        return availSlot;
    }
};