#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        for (int i = 0; i < k - 1; ++i) {
            while (dq.size() && nums[i] >= dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
        }

        vector<int> res;
        
        dq.push_front({-1, -1});
        for (int i = 0; i <= nums.size() - k; ++i) {
            if (dq.front().second == i - 1) {
                dq.pop_front();
            }

            while (dq.size() && nums[i + k - 1] >= dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({nums[i + k - 1], i + k - 1});

            res.push_back(dq.front().first);
        }

        return res;
    }
};
