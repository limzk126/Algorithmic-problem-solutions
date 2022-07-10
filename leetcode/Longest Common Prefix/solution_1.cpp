#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        string lcp = "";

        int n = INT_MAX;
        for (auto str : strs) {
            n = min(n, (int) str.size()); 
        }

        while (idx < n) {
            int ch = strs[0][idx];
            for (int i = 1; i < strs.size(); ++i) {
               if (strs[i][idx] != ch) {
                   return lcp;
               }
            }

            lcp += ch;
            ++idx;
        }

        return lcp;
    }
};
