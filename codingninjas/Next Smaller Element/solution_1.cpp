#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    stack<pair<int, int>> steak;
    
    for (int i = 0; i < n; ++i) {
        int num = arr[i];
        while (steak.size() && steak.top().first > num) {
            mp[steak.top().second] = num;
            steak.pop();
        }

        steak.push({num, i});
    }

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (mp.find(i) == mp.end()) {
            res.push_back(-1);
            continue;
        }

        res.push_back(mp[i]);
    }

    return res;
}
