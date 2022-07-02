#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;

        stack<int> steak;        
        for (int i = 0; i < nums2.size(); ++i) {
            while (steak.size() && steak.top() < nums2[i]) {
                mp[steak.top()] = nums2[i];
                steak.pop();
            }
            
            steak.push(nums2[i]);
        }

        vector<int> res;
        for (auto num : nums1) {
            if (mp.find(num) == mp.end()) {
                res.push_back(-1);
                continue;
            }
            
            res.push_back(mp[num]);
        }

        return res;
    }
};

