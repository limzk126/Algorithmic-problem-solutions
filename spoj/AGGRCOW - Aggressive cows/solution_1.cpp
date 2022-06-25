#include <bits/stdc++.h>
using namespace std;

int checkMaxAlloc(vector<int>& v, int gap) {
    int cnt = 1;
    int prev = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] - prev >= gap) {
	        ++cnt;
	        prev = v[i];
	    }
    }

    return cnt;
}

int main() {
    int t;
    int N, C;
    cin >> t;
    while (t--) {
        cin >> N >> C;
        
        vector<int> stalls;
        for (int i = 0; i < N; ++i) {
            int tmp;
            cin >> tmp;
            stalls.push_back(tmp);
        }
        sort(stalls.begin(), stalls.end());

        int low = 0;
        int high = 1e9 + 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (checkMaxAlloc(stalls, mid) >= C) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << high << "\n";
    }
}
