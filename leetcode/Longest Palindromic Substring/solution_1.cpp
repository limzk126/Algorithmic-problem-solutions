#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool isPalindrome[n][n];
        int max = 0;
        int l, r;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= n - i; ++j) {
                int k = j + i - 1;
                if (j == k || j + 1 == k) {
                    isPalindrome[j][k] = true;
                    continue;
                }
                
                isPalindrome[j][k] = isPalindrome[j + 1][k - 1];
                if (isPalindrome[j][k]) {
                    if (k - j + 1 > max) {
                        max = k - j + 1;
                        l = j, r = k;
                    }
                }
            }
        }

        return s.substr(l, max);
    }
};

