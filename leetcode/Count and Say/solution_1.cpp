#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            string s = "1";

            while (--n) {
                int i = 0;
                string tmp = "";

                while (i < s.size()) {
                    int j = i;
                    while (i < s.size() && s[j] == s[i]) i++;
                    int cnt = i - j;
                    tmp += ((char) '0' + cnt);
                    tmp += s[j];
                }

                s = tmp;
            }

            return s;
        }
};
