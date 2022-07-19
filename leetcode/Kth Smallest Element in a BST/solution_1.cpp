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
    int traverse(TreeNode* root, int k, int additional, int& res) {
        if (root == nullptr) return 0;

        int leftSubSize = traverse(root->left, k, additional, res);
        
        if (additional + leftSubSize + 1 == k) res = root->val;

        int rightSubSize = traverse(root->right, k, additional + leftSubSize + 1, res);

        return leftSubSize + 1 + rightSubSize;
    }

    int kthSmallest(TreeNode* root, int k) {
        int res;

        traverse(root, k, 0, res);

        return res;
    }
};
