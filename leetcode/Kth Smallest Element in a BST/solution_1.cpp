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

/**
 * The intuition here is that to find out if a node is the Kth smallest element,
 * you have to check if the sum of nodes smaller than the current node plus itself
 * is equal to K.
 * We know that when we move down the left child, the amount of nodes smaller than
 * the left child would not increase.
 * However, if we move down towards the right child, the amount of nodes smaller than
 * the right child would increment by the size of the subtree rooted at the left child
 * plus the parent itself.
 */
