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
            TreeNode* cur = root;

            while (cur != nullptr) {
                if (cur->left == nullptr) {
                    res.push_back(cur->val);
                    cur = cur->right;
                } else {
                    TreeNode* last = cur->left;

                    while (last->right && last->right != cur) {
                        last = last->right;
                    }

                    if (last->right == nullptr) {
                        res.push_back(cur->val);
                        last->right = cur;
                        cur = cur->left;
                        continue;
                    } 

                    if (last->right == cur) {
                        last->right = nullptr;
                        cur = cur->right;
                    }
                }
            }

            return res;
        }
};
