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
    Node* connect(Node* root) {
        Node* cur = root;

        while (cur) {
            Node* tmp = cur;
            while (tmp) {
                if (tmp->left) {
                    tmp->left->next = tmp->right;
                    
                    if (tmp->next) {
                        tmp->right->next = tmp->next->left;
                    }
                }

                tmp = tmp->next;
            }
            cur = cur->left; 
        }

        return root;
    }
};
