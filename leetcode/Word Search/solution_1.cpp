class Solution {
    public:
    bool search(vector<vector<char>>& board, string& word, int idx, int r, int c) {
        if (idx == word.size()) return true;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return false;
        if (word[idx] != board[r][c]) return false;
        
        char tmp = board[r][c];
        board[r][c] = '#';

        bool res = search(board, word, idx + 1, r - 1, c) ||
            search(board, word, idx + 1, r, c + 1) ||
            search(board, word, idx + 1, r + 1, c) ||
            search(board, word, idx + 1, r, c - 1);
        
        board[r][c] = tmp;
        
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (search(board, word, 0, i, j)) return true;
            }
        }
        
        return false;
    }
};
