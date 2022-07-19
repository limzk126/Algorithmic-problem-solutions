#include <bits/stdc++.h>
using namespace std;

/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
int traverse(TreeNode<int>* root, int k, int additional, int& res) {
    if (root == NULL) return 0;

    int rightSubSize = traverse(root->right, k, additional, res);

    if (additional + rightSubSize + 1 == k) res = root->data;

    int leftSubSize = traverse(root->left, k, additional + rightSubSize + 1, res);

    return leftSubSize + 1 + rightSubSize;
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int res = -1;

    traverse(root, k, 0, res);

    return res;
}
