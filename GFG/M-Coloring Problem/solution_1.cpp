// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool search(vector<int>& color, vector<vector<int>>& adj, int pos, int n, int m) {
    if (pos == n) {
        return true;
    }
    
    for (int i = 0; i < m; ++i) {
        bool isOk = true;
        for (int j = 0; j < adj[pos].size(); ++j) {
            if (color[adj[pos][j]] == i) {
                isOk = false;
                break;
            }
        }
        
        if (!isOk) continue;
        
        color[pos] = i;
        if (search(color, adj, pos + 1, n, m)) return true;
        color[pos] = -1; 
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    
    vector<vector<int>> adj(n, vector<int>{});
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j]) {
                adj[i].push_back(j);
            }
        }
    }
    
    vector<int> color(n, -1);
    return search(color, adj, 0, n, m);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends