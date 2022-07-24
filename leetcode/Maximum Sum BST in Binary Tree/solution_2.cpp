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
    vector<int> traverse(TreeNode* root, int& res) {
        if (!root) return {INT_MAX, INT_MIN, 0};

        vector<int> l(traverse(root->left, res)), r(traverse(root->right, res));
        
        if (l.empty() || r.empty() || root->val <= l[1] || root->val >= r[0]) return {};

        int sum = l[2] + root->val + r[2];
        res = max(res, sum);

        return {min(l[0], root->val), max(r[1], root->val), sum};
    }

        
    int maxSumBST(TreeNode* root) {
        int res = 0;
        traverse(root, res);

        return res;
    }
};
