#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    string serializedTree;

    void traverse(TreeNode* root) {
        if (!root) {
            serializedTree += 'n';
            return;
        }

        serializedTree += to_string(root->val);
        serializedTree += 's';

        traverse(root->left);
        traverse(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        traverse(root); 
        return serializedTree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<TreeNode*> s;
        
        int i = 0;
        TreeNode* res = nullptr;
        while (i < data.size()) {
            bool first = true;
            while (data[i] != 'n') {
                string tmp = "";
                while (data[i] != 's') {
                    tmp += data[i];
                    ++i;
                }
                
                ++i;

                TreeNode *node = new TreeNode(stoi(tmp));

                if (first) {
                    if (s.empty()) {
                        res = node;
                    } else {
                        s.top()->right = node;
                        s.pop();
                    }

                    first = false;
                } else {
                    s.top()->left = node;
                }
                
                s.push(node);
            }

            if (data[i] == 'n' && first) s.pop();

            ++i;
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
