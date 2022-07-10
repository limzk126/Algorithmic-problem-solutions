#include <bits/stdc++.h>
using namespace std;

int Solution::solve(string A) {
    int n = A.size();
    string B;
    B.resize(A.size());
    reverse_copy(A.begin(), A.end(), B.begin());

    A += '#' + B;
    int piLen = n * 2 + 1;
    vector<int> pi(piLen, 0);

    for (int i = 1; i < piLen; ++i) {
        int j = pi[i - 1];
        while (j > 0 && A[j] != A[i]) {
            j = pi[j - 1];
        }

        if (A[j] == A[i]) {
            ++j;
        }

        pi[i] = j;
    }

    if (pi[piLen - 1] >= n) {
        return 0;
    }

    return n - pi[piLen - 1];
}

