//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        vector<int>* adj;

        void myDfs(int v, vector<bool>& visited, vector<int>& res) {
            if (visited[v]) return;
            visted[v] = true;
            res.push_back(v);

            for (auto n : adj[v]) {
                myDfs(n, visited, res);
            }
        }

        // Function to return a list containing the DFS traversal of the graph.
        vector<int> dfsOfGraph(int V, vector<int> adj[]) {
            this->adj = adj;
            vector<bool> visited(V, false);
            vector<int> res;

            myDfs(0, visited, res);

            return res;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
