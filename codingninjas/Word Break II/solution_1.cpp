#include <unordered_set>

void search(string &s, int pos, vector<string>& cur, unordered_set<string>& us, vector<string>& res) {
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
        if (us.find(word) != us.end()) {
            cur.push_back(word);
            search(s, i + 1, cur, us, res);
            cur.pop_back();
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_set<string> us;
    
    for (auto str : dictionary) {
        us.insert(str);
    }
    
    vector<string> cur;
    vector<string> res;
    search(s, 0, cur, us, res);
    
    return res;
}