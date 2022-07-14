/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int maxPathSum(TreeNode* cur, int& res) {
        if (cur == nullptr) return 0;
        
        int maxLeft = maxPathSum(cur->left, res);
        int maxRight = maxPathSum(cur->right, res);
        
        int curMax = cur->val;
        
        curMax = max(curMax, maxLeft + cur->val);
        curMax = max(curMax, maxRight + cur->val);
        
        res = max(res, curMax);
        res = max(res, maxLeft + cur->val + maxRight);
         
        return curMax;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        
        maxPathSum(root, res);
        
        return res;
    }
};
