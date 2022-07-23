#include <bits/stdc++.h>
using namespace std;

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
    int res = 0;
    
    bool traverse(TreeNode* root, int& lowerBound, int& upperBound, int& sum) {
        if (root == nullptr) return true;
       
        int leftSum = 0, rightSum = 0;
        int leftLowerBound = INT_MIN, leftUpperBound = INT_MIN;
        int rightLowerBound = INT_MAX, rightUpperBound = INT_MAX;
        bool isLeftTree = traverse(root->left, leftLowerBound, leftUpperBound, leftSum);
        bool isRightTree = traverse(root->right, rightLowerBound, rightUpperBound, rightSum);
        
        bool isValid = isLeftTree && isRightTree && root->val > leftUpperBound && root->val < rightLowerBound;
        
        sum = leftSum + root->val + rightSum;
        lowerBound = leftLowerBound, upperBound = rightUpperBound;
        if (!root->left) lowerBound = root->val;
        if (!root->right) upperBound = root->val;
        
        if (isValid) res = max(res, sum);
        
        return isValid;
    }
    
    int maxSumBST(TreeNode* root) {
        int tmp1, tmp2, tmp3;
        traverse(root, tmp1, tmp2, tmp3);
        
        return res;
    }
};
