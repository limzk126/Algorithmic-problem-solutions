class Solution {
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> color(n, -1);

            for (int i = 0; i < n; ++i) {
                if (color[i] != -1) continue;
                
                color[i] = 0;
                
                if (!bipartite(i, graph, color)) return false;
            }

            return true;
        }
    private:
        bool bipartite(int v, vector<vector<int>>& graph, vector<int>& color) {
            int vColor = color[v];

            for (auto n : graph[v]) {
                if (color[n] == -1) {
                    color[n] = vColor ^ 1;
                    if (!bipartite(n, graph, color)) return false;
                } else {
                    if (color[n] == vColor) {
                        return false;
                    }
                }
            }

            return true;
        }
};
