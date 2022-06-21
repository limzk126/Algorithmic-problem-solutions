class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (!(mid & 1)) {
                if (mid + 1 < (nums.size()) && nums[mid + 1] == nums[mid]) {
                    low = mid + 1;
                    continue;
                }
                
                if (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
                    high = mid - 1;
                    continue;
                }
                
                return nums[mid];
            } else {
                if (mid + 1 < (nums.size()) && nums[mid + 1] == nums[mid]) {
                    high = mid - 1;
                    continue;
                }
                
                low = mid + 1;
            }
        }
        
        return 1234;
    }
};