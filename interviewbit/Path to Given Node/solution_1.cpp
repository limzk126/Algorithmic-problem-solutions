#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void traverse(TreeNode* cur, int target, vector<int>& path, vector<int>& res) {
    if (cur == NULL) return;

    path.push_back(cur->val);

    if (cur->val == target) {
        res = path;
    }

    traverse(cur->left, target, path, res);
    traverse(cur->right, target, path, res);

    path.pop_back();
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    vector<int> res;

    traverse(A, B, path, res);

    return res;
}

