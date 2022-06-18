// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    void search(vector<vector<int>>& m, int x, int y, string& route, int n, vector<string>& res) {
        if (m[y][x] == -1 || m[y][x] == 0) return;
        
        if (x == n - 1 && y == n - 1) {
            res.push_back(route);
            return;
        }
        
        int cache = m[y][x];
        m[y][x] = -1;
        
        if (y - 1 >= 0) {
            route.push_back('U');
            search(m, x, y - 1, route, n, res);
            route.pop_back();
        }
        
        if (x + 1 < n) {
            route.push_back('R');
            search(m, x + 1, y, route, n, res);
            route.pop_back();
        }
        
        if (y + 1 < n) {
            route.push_back('D');
            search(m, x, y + 1, route, n, res);
            route.pop_back();
        }
        
        if (x - 1 >= 0) {
            route.push_back('L');
            search(m, x - 1, y, route, n, res);
            route.pop_back();
        }
        
        m[y][x] = cache;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> res;
        string route = "";
        
        search(m, 0, 0, route, n, res);
        
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends