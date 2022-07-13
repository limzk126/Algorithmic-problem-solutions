#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void traverse(BinaryTreeNode<int> *root, vector<vector<int>>& v) {
    if (root == NULL) return;

    v[1].push_back(root->data);
    traverse(root->left, v);
    v[0].push_back(root->data);
    traverse(root->right, v);
    v[2].push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> res = {{}, {}, {}}; 

    traverse(root, res); 

    return res;
}
