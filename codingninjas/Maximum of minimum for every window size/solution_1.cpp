#include <bits/stdc++.h>
using namespace std;

vector<int> prev_smallest(vector<int>& a, int n) {
    vector<int> res(n);
    stack<int> steak;


    for (int i = 0; i < n; ++i) {
        while (steak.size() && a[steak.top()] >= a[i]) {
            steak.pop();
        }

        if (steak.size()) {
            res[i] = steak.top();
        } else {
            res[i] = -1;
        }

        steak.push(i);
    }

    return res;
}

vector<int> next_smallest(vector<int>& a, int n) {
    vector<int> res(n);
    stack<int> steak;

    for (int i = n - 1; i >= 0; --i) {
        while (steak.size() && a[steak.top()] >= a[i]) {
            steak.pop();
        }

        if (steak.size()) {
            res[i] = steak.top();
        } else {
            res[i] = n;
        }

        steak.push(i);
    }

    return res;
}

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> l = prev_smallest(a, n);
    vector<int> r = next_smallest(a, n);
    vector<int> res(n, INT_MIN);

    for (int i = 0; i < n; ++i) {
        int range = r[i] - l[i] - 1;
        res[range - 1] = max(res[range - 1], a[i]);
    }

    int mx = res[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        mx = max(mx, res[i]);
        res[i] = mx;
    }

    return res;
}


