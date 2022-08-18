class Solution {
    public:
        void search(vector<int>& nums, int idx, vector<int>& container, vector<vector<int>>& res) {
            if (idx == nums.size()) return res.push_back(container); 

            container.push_back(nums[idx]);
            search(nums, idx + 1, container, res);
            container.pop_back();
            search(nums, idx + 1, container, res);
        }

        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> container;
            vector<vector<int>> res;

            search(nums, 0, container, res);

            return res;
        }
};
