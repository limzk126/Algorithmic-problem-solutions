/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int i, int j, int target, int color)
    {
        int m = image.size();
        int n = image[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] == color || image[i][j] != target)
            return;
        image[i][j] = color;
        dfs(image, i - 1, j, target, color);
        dfs(image, i, j + 1, target, color);
        dfs(image, i + 1, j, target, color);
        dfs(image, i, j - 1, target, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
// @lc code=end
