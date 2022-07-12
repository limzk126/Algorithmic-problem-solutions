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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        stack<TreeNode*> steak;
        steak.push(root);

        while (steak.size()) {
            TreeNode* cur = steak.top();

            if (cur->val != NULL) res.push_back(cur->val);
            cur->val = NULL;

            if (cur->left != nullptr) {
                steak.push(cur->left);
                cur->left = nullptr;
            } else {
                steak.pop();
                if (cur->right != nullptr) steak.push(cur->right);
            }
        }

        return res;
    }
};
