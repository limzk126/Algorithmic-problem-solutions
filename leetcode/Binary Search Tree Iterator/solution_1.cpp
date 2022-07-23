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
class BSTIterator {
public:
    stack<TreeNode*> s;
    TreeNode* curNode;

    BSTIterator(TreeNode* root) {
       curNode = root;
    }
    
    int next() {
        while (curNode || !s.empty()) {
            if (curNode) {
                s.push(curNode);
                curNode = curNode->left;
            } else {
                curNode = s.top();
                s.pop();
                int val = curNode->val;
                curNode = curNode->right;
                return val;
            }
        }

        return -1;
    }
    
    bool hasNext() {
        return curNode || !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
