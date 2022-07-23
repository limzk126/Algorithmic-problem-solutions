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
class BstIterator {
    public:
        stack<TreeNode*> s;
        TreeNode* curNode;
        int curVal;
        bool isForward;

        BstIterator(TreeNode* root, bool isForward) : curNode(root), isForward(isForward) {
            (*this)++;
        }

        void operator++(int) {
            while (curNode || !s.empty()) {
                if (curNode) {
                    s.push(curNode);
                    curNode = isForward ? curNode->left : curNode->right;
                } else {
                    curNode = s.top();
                    s.pop();
                    curVal = curNode->val;
                    curNode = isForward ? curNode->right : curNode->left;
                    break;
                }
            }
        }

        int operator * () {
            return curVal;
        }
};

class Solution {
    public:
        bool findTarget(TreeNode* root, int k) {
            if (!root) return false;

            BstIterator l{root, true};
            BstIterator r{root, false};

            while (*l < *r) {
                int sum = *l + *r;

                if (sum == k) {
                    return true;
                } else if (sum < k) {
                    l++;
                } else {
                    r++;
                }
            }

            return false;
        }
};

/*
 * Time O(N)
 * Space: O(logN)
 */
