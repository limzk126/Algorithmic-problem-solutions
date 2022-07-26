class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj(numCourses);

            for (auto pair : prerequisites) {
                adj[pair[1]].push_back(pair[0]);
            }

            vector<bool> done(numCourses, false), todo(numCourses, false);
            for (int i = 0; i < numCourses; ++i) {
                if (!done[i] && !acyclic(i, adj, done, todo)) {
                    return false;
                }
            }

            return true;
        }
    private: 
        bool acyclic(int v, vector<vector<int>>& adj, vector<bool>& done, vector<bool>& todo) {
            if (todo[v]) return false;

            if (done[v]) return true;

            todo[v] = done[v] = true;
            
            for (auto n : adj[v]) {
                if (!acyclic(n, adj, done, todo)) return false;
            }

            todo[v] = false;

            return true;
        }
};
