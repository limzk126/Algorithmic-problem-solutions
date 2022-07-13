// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    int min_left = INT_MAX, max_right = INT_MIN;

    void traverse(Node *root, int pos, int level, unordered_map<int, pair<int, int>>& mp) {
        if (root == NULL) return;

        if (mp.find(pos) == mp.end()) {
            mp[pos] = {root->data, level};
        } else {
            pair<int, int> p = mp[pos];

            if (level >= p.second) {
                mp[pos] = {root->data, level};
            }
        }

        min_left = min(min_left, pos);
        max_right = max(max_right, pos);

        traverse(root->left, pos - 1, level + 1, mp);
        traverse(root->right, pos + 1, level + 1, mp);
    }

    vector <int> bottomView(Node *root) {
        unordered_map<int, pair<int, int>> mp;
        vector<int> res;

        traverse(root, 0, 0, mp);

        if (min_left == INT_MAX && max_right == INT_MIN) return res;

        for (int i = min_left; i <= max_right; ++i) {
            res.push_back(mp[i].first);
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


  // } Driver Code Ends
