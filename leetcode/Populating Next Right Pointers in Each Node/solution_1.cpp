#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
    void traverse(Node* cur, Node* parent) {
        if (parent && parent->next) {
            if (cur->next == NULL) cur->next = parent->next->left; 
        }
        
        if (cur->left && cur->right) {
            cur->left->next = cur->right;
            traverse(cur->right, cur);
            traverse(cur->left, cur);
        }
    }
    
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        traverse(root, nullptr);

        return root;
    }
};
