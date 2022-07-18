/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int leftVal = -1;
    int rightVal = -1;
    while (true) {
        if (root == NULL) return {-1, -1};
        
        if (root->data == key) break;
        
        if (key < root->data) {
            rightVal = root->data;
            root = root->left;
        }
        if (key > root->data) {
            leftVal = root->data;
            root = root->right;
        }
    }
    
    BinaryTreeNode<int>* lowerBound = root->left;
    BinaryTreeNode<int>* upperBound = root->right;
    
    while (lowerBound && lowerBound->right) lowerBound = lowerBound->right;
    while (upperBound && upperBound->left) upperBound = upperBound->left;
    
    if (lowerBound) leftVal = lowerBound->data;
    if (upperBound) rightVal = upperBound->data;
    
    return {leftVal, rightVal};
}
