class Solution {
public:
    int getPivot(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] >= nums[0]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
    }
    
    int search(vector<int>& nums, int target) {
        int low;
        int high;
        int n = nums.size();
        
        if (nums[0] <= nums[n - 1]) {
            low = 0;
            high = n - 1;
        } else {
            int pivot = getPivot(nums);
            if (nums[0] > target) {
                low = pivot;
                high = n - 1;
            } else {
                low = 0;
                high = pivot - 1;
            }
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};