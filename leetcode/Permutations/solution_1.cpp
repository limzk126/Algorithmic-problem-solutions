class Solution {
private:
    void rec(vector<int>& nums, int pos, vector<vector<int>>& res) {
        int n = nums.size();
        
        if (pos == n) {
            res.push_back(nums);
            return;
        }
        
        for (int i = pos; i < n; ++i) {
            swap(nums[pos], nums[i]);
            rec(nums, pos + 1, res);
            swap(nums[pos], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        rec(nums, 0, res);
        
        return res;
    }
};

/*
 * TC: O(n! * n)
 * SC: O(1)
 */