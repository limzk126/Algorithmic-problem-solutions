class Solution {
public:
    void rec(vector<int>& candidates, vector<int>& tmp, int pos, int sum, int target, vector<vector<int>>& res) {
        if (sum >= target) {
            if (sum == target) res.push_back(tmp);
            return;
        }
        
        int n = candidates.size();
        for (int i = pos; i < n; ++i) {
            if (i != pos && candidates[i - 1] == candidates[i]) continue;
            tmp.push_back(candidates[i]);
            rec(candidates, tmp, i + 1, sum + candidates[i], target, res);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;
        vector<int> tmp;
        rec(candidates, tmp, 0, 0, target, res);
        
        return res;
    }
};