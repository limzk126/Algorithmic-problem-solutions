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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        stack<TreeNode*> steak;
        steak.push(root);

        while (steak.size()) {
            TreeNode* cur = steak.top();

            if (cur->left == nullptr && cur->right == nullptr) {
                res.push_back(cur->val);
                steak.pop();
                continue;
            }

            if (cur->left != nullptr) {
                steak.push(cur->left);
                cur->left = nullptr;
                continue;
            } 

            if (cur->right != nullptr) {
                steak.push(cur->right);
                cur->right = nullptr;
            }
        }

        return res;
    }
};
