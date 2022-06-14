class Solution {
public:
    void rec(string s, int pos, vector<string>& tmp, vector<vector<string>>& res) {
        if (pos >= s.size()) {
            if (tmp.size()) res.push_back(tmp);
            return;
        }
        
        string str = "";
        string r_str = "";
        for (int i = pos; i < s.size(); ++i) {
            str += s[i];
            r_str = s[i] + r_str;
            if (str != "" && str == r_str) {
                tmp.push_back(str);
                rec(s, i + 1, tmp, res);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        
        rec(s, 0, tmp, res);
        
        return res;
    }
};