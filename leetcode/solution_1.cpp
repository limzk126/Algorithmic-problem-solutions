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
    void insertTraverse(TreeNode* root, queue<int*>& v) {
        if (root == NULL) {
            v.push(NULL);
            return;
        }
        
        v.push(&root->val);
        insertTraverse(root->left, v);
        insertTraverse(root->right, v);
    }
    
    void removeTraverse(TreeNode* root, queue<int*>& q) {
        int* cur = q.front();
        if (root == NULL || cur == NULL) {
            if (root == NULL && cur == NULL) q.pop();
            return;
        }
        
        if (*cur == root->val) {
            q.pop();
        } 
        
        removeTraverse(root->right, q);
        removeTraverse(root->left, q);
    }
    
    bool isSymmetric(TreeNode* root) {
        queue<int*> q;
        
        insertTraverse(root, q);
        removeTraverse(root, q);
        
        return q.size() == 0;
    }
};
