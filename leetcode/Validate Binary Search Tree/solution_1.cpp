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
    bool checkValidity(TreeNode* root, int* lowerBound, int* upperBound) {
        if (root == nullptr) return true;
        
        bool aboveLowerBound = lowerBound == nullptr || root->val > *lowerBound;
        bool belowUpperBound = upperBound == nullptr || root->val < *upperBound;

        if (!aboveLowerBound || !belowUpperBound) return false;

        bool leftValid = checkValidity(root->left, lowerBound, &root->val);
        bool rightValid = checkValidity(root->right, &root->val, upperBound);

        return leftValid && rightValid;
    }

    bool isValidBST(TreeNode* root) {
        return checkValidity(root, nullptr, nullptr);
    }
};
