#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int res = 0;
        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ') ++i;

        if (i < n && s[i] == '+') {
            sign = 1;
            ++i;
        } else if (i < n && s[i] == '-') {
            sign = -1;
            ++i;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN; 
            }

            res = res * 10 + digit;
            ++i;
        }

        return sign * res;
    }
};
