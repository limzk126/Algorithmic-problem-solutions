#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ns = needle.size();
        int hs = haystack.size();

        vector<int> pi(ns, 0);
        for (int i = 1; i < ns; ++i) {
            int j = pi[i - 1];
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                pi[i] = j + 1;
            }
        }
        
        int match_idx = 0;
        int i = 0;

        while (i < hs) {
            if (haystack[i] == needle[match_idx]) {
                if (match_idx == ns - 1) return i - ns + 1;
                ++i;
                ++match_idx;
            } else {
                if (match_idx == 0) {
                    ++i;
                } else {
                    match_idx = pi[match_idx - 1];
                }
            }
        }

        return -1;
    }
};
