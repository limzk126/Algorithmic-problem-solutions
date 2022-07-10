#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rev(string& s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }

    string reverseWords(string s) {
        int i = 0, j = 0, k = 0;
        int count = 0;

        while (true) {
            while (j < s.size() && s[j] == ' ') ++j;

            if (j == s.size()) break;

            if (count) s[i++] = ' ';

            k = j;
            while (k < s.size() && s[k] != ' ') s[i++] = s[k++];

            rev(s, j, k - 1);
        }

        s.resize(i);
        rev(s, 0, i - 1);

        return s;
    }
};
