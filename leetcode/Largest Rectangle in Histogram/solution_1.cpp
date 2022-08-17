#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int area = 0;
        int n = heights.size(); 
        for (int i = 0; i <= n; ++i) {
            int h = i == n ? 0 : heights[i];
            
            if (s.empty() || heights[s.top()] <= h) {
                s.push(i); 
            } else {
                int tp = s.top();
                s.pop();
                area = max(area, heights[tp] * (s.empty() ? i : i - s.top() - 1));
                --i;
            }
        }
        
        return area;
    }
};
