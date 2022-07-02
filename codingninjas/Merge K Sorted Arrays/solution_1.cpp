#include <vector>
#include <queue>

using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{	
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < k; ++i) {
        for (auto val : kArrays[i]) {
            q.push(val);
        }
    }

    vector<int> res;
    while(q.size()) {
        res.push_back(q.top());
        q.pop();
    }

    return res;
}

