class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> waterHeight(height.size(), 0);
        
        int mx = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] < mx) {
                waterHeight[i] = mx;
            }
            
            mx = max(mx, height[i]);
        }
        
        mx = 0;
        int sum = 0;
        for (int i = (int)height.size() - 1; i >= 0; --i) {
            int tmp = min(waterHeight[i], mx);
            tmp -= height[i];
            
            if (tmp < 0) tmp = 0;
            
            sum += tmp;
            mx = max(mx, height[i]);
        }
        
        return sum;
    }
};

/*
 * Reduce the problem by looking at each position individually.
 * Notice that the height of the water that can be collected at a position is
 * the minimum of the max elevation to its left and the max elevation to its right,
 * and then minus off the position's elevation.
 * We can a achieve an O(n) solution by traversing forward first by taking into account the
 * max elevation to the left, and then traversing backwards to take into account the max
 * elevation to its right.
 */