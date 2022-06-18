class Solution {
private:
    void rec(string& row, vector<string>& cur, vector<vector<string>>& res, int n) {
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }
        
        int rowLength = row.size();
        
        for (int i = 0; i < rowLength; ++i) {
            
            int precedingRows = cur.size();
            bool ok = 1;
            for (int j = precedingRows - 1, k = 1; j >= 0; --j, k++) {
                if (i + k < rowLength && cur[j][i + k] == 'Q') {
                    ok = !ok;
                    break;
                }
                
                if (i - k >= 0 && cur[j][i - k] == 'Q') {
                    ok = !ok;
                    break;
                }
                
                if (cur[j][i] == 'Q') {
                    ok = !ok;
                    break;
                }
            }
            
            if (!ok) continue;
            
            swap(row[i], row[0]);
            cur.push_back(row);
            swap(row[i], row[0]);
            rec(row, cur, res, n);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        string row = "Q";
        string dots(n - 1, '.');
        row += dots;
        
        vector<string> cur;
        vector<vector<string>> res;
        
        rec(row, cur, res, n);
        
        return res;
    }
};