#include <bits/stdc++.h>
using namespace std;

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    int min_left = INT_MAX, max_right = INT_MIN;

    void traverse(Node* root, int pos, int level, unordered_map<int, pair<int, int>>& mp) {
        if (root == NULL) return;
       
        if (mp.find(pos) == mp.end()) {
            mp[pos] = {root->data, level};
        } else {
            pair<int, int> p = mp[pos];

            if (level <= p.second) {
                mp[pos] = {root->data, level};
            }
        }

        min_left = min(min_left, pos);
        max_right = max(max_right, pos);

        traverse(root->left, pos - 1, level + 1, mp);
        traverse(root->right, pos + 1, level + 1, mp);
    }

    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        unordered_map<int, pair<int, int>> mp;
        vector<int> res;

        traverse(root, 0, 0, mp);

        if (min_left == INT_MIN && max_right == INT_MAX) return res;

        for (int i = min_left; i <= max_right; ++i) {
            res.push_back(mp[i].first);
        }
        
        return res;
    }

};
