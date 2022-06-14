class Solution {
public:
    void rec(vector<int>& candidates, int pos, int sum, int target, vector<int> tmp, vector<vector<int>>& res) {
        if (sum == target) {
            res.push_back(tmp);
            return;
        }
        
        if (pos == candidates.size()) return;
        
        int cummulative = sum;
        while (cummulative <= target) {
            rec(candidates, pos + 1, cummulative, target, tmp, res);
            cummulative += candidates[pos];
            tmp.push_back(candidates[pos]);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        
        rec(candidates, 0, 0, target, tmp, res);
        return res;
    }
};