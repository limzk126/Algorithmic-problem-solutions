#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool match(string a, string b) {
        const int p = 31;
        const int m = 1e9 + 9;
        int A = a.size(), B = b.size();

        vector<long long> p_pow(max(A, B));
        p_pow[0] = 1;
        for (int i = 1; i < (int) p_pow.size(); ++i) {
            p_pow[i] = (p_pow[i - 1] * p) % m;
        }

        vector<long long> hashA(A + 1, 0);
        for (int i = 0; i < A; ++i) {
            hashA[i + 1] = (hashA[i] + (a[i] - 'a' + 1) * p_pow[i]) % m;
        }

        long long bHashValue = 0;
        for (int i = 0; i < B; ++i) {
            bHashValue = (bHashValue + (b[i] - 'a' + 1) * p_pow[i]) % m;
        }
        
        for (int i = 0; i + B < A + 1; ++i) {
            long long curHash = (hashA[i + B] - hashA[i] + m) % m;
            if (curHash == (bHashValue * p_pow[i]) % m) {
                return true;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string tmp = a;
        int count = 1;
        while (tmp.size() < b.size()) {
            tmp += a;
            ++count;
        }

        if (match(tmp, b)) return count;
        tmp += a;
        if (match(tmp, b)) return count + 1;

        return -1;
    }
};
