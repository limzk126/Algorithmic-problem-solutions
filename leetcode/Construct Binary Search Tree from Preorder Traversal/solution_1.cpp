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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> steak;
        TreeNode* res = new TreeNode(preorder[0]);
        steak.push(res);
        
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* newNode = new TreeNode(preorder[i]);
            
            if (steak.top()->val > preorder[i]) {
                steak.top()->left = newNode;
            } else {
                TreeNode* prev = nullptr;
                while (steak.size() && steak.top()->val < preorder[i]) {
                    prev = steak.top();
                    steak.pop();
                }
                
                prev->right = newNode;
            }
            
            steak.push(newNode);
        }
        
        return res;
    }
};
