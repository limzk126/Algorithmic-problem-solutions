class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int res = INT_MIN;
        int n = heights.size();
        for (int i = 0; i <= n; ++i) {
            int h = i == n ? 0 : heights[i];
            if (s.empty()) {
                s.push({h, 1});
            } else {
                int cnt = 0;
                while (!s.empty() && s.top().first >= h) {
                    res = max(res, s.top().first * (cnt + s.top().second));
                    cnt += s.top().second;
                    s.pop();
                }
                
                s.push({h, cnt + 1});
            }
        }
        
        return res;
    }
};
