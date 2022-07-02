#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = 1;
                continue;
            }

            mp[nums[i]]++;
        }
        auto Compare = [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(Compare)> q(Compare);
        
        for (auto kvp : mp) {
            q.push({kvp.first, kvp.second});
        }

        vector<int> res;
        while (k--) {
            res.push_back(q.top().first);
            q.pop();
        }

        return res;
    }
};
