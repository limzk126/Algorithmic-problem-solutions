#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, node*> m;

    Node* cloneGraph(Node* node) {
        if (m.find(node->val) != m.end()) return m[node->val];

        Node* res = new Node(node->val);
        m[node->val] = res;

        for (int i = 0; i < node->neighbors.size(); ++i) {
            Node* cur = CloneGraph(node->neighbor[i]);
            res->neighbors.push_back(cur);
        }
        
        return res;
    }
};
