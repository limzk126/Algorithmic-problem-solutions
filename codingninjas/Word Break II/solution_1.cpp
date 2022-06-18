#include <unordered_map>

void search(string &s, int pos, vector<string>& cur, unordered_map<string, bool>& um, vector<string>& res) {
    int n = s.size();
    
    if (pos == n) {
        string s = "";
        int sz = 0;
        for (auto str : cur) {
            s += str + ' ';
            sz += str.size();
        }
        s.pop_back();
        if (sz == n) res.push_back(s);
        return;
    }
    
    string word = "";
    for (int i = pos; i < n; ++i) {
        word += s[i];
        if (um.find(word) != um.end()) {
            cur.push_back(word);
            search(s, i + 1, cur, um, res);
            cur.pop_back();
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<string, bool> um;
    
    for (auto str : dictionary) {
        um[str] = true;
    }
    
    vector<string> cur;
    vector<string> res;
    search(s, 0, cur, um, res);
    
    return res;
}