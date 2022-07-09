#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, int> mp;

    int romanToInt(string s) {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int sum = mp[s[0]];
        for (int i = 1; i < s.size(); ++i) {
            int& cur = mp[s[i]], prev = mp[s[i - 1]];
            if (cur > prev) {
                sum -= 2 * prev; 
            }

            sum += cur; 
        }

        return sum;
    }
};

