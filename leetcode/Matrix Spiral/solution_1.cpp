cLass Solution {
    public:
        bool traverse(char dir, vector<vector<int>>& matrix, int r, int c, vector<int>& res) {
            if (r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size()) return false;
            if (matrix[r][c] == 101) return false;
            res.push_back(matrix[r][c]);
            matrix[r][c] = 101; 

            if (dir == 'U') {
                int ok = traverse('U', matrix, r - 1, c, res);
                if (!ok) traverse('R', matrix, r, c + 1, res);
            } else if (dir == 'R') {
                int ok = traverse('R', matrix, r, c + 1, res);
                if (!ok) traverse('D', matrix, r + 1, c, res);
            } else if (dir == 'D') {
                int ok = traverse('D', matrix, r + 1, c, res);
                if (!ok) traverse('L', matrix, r, c - 1, res);
            } else {
                int ok = traverse('L', matrix, r, c - 1, res);
                if (!ok) traverse('U', matrix, r - 1, c, res);
            }
            return true;
        }

        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> res;
            traverse('R', matrix, 0, 0, res);
            return res;
        }
};
