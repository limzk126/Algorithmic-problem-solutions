#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> maxNumOfSubstrings(string s) {
            vector<int> mins(26, INT_MAX - 1);
            vector<int> maxs(26, -1);
            vector<int> exists(26, false);
            vector<vector<int>> prefixSum(s.size() + 1, vector<int>(26, 0));
            for (int i = 0; i < s.size(); ++i) {
                prefixSum[i + 1] = prefixSum[i];
                prefixSum[i + 1][s[i] - 'a']++;
                mins[s[i] - 'a'] = min(mins[s[i] - 'a'], i);
                maxs[s[i] - 'a'] = max(maxs[s[i] - 'a'], i);
                exists[s[i] - 'a'] = true;
            }
            
            vector<vector<bool>> graph(26, vector<bool>(26, false));
            for (int i = 0; i < 26; ++i) {
                if (!exists[i]) continue;

                for (int j = 0; j < 26; ++j) {
                    if (prefixSum[maxs[i] + 1][j] - prefixSum[mins[i] + 1][j] > 0) {
                        graph[i][j] = true;
                    }
                }
            }
            
            
            stack<int> st;
            vector<bool> visited(26, false);
            for (int i = 0; i < 26; ++i) {
                if (!exists[i] || visited[i]) continue;
                dfs1(i, graph, st, visited);
            }
            
            int batch = 0;
            vector<int> batches(26, -1);
            vector<int> degree(26, 0); // Out degree of each SCC/Batch
            while (!st.empty()) {
                int v = st.top();
                st.pop();

                if (batches[v] != -1) continue;
                dfs2(v, graph, batches, batch, degree);
                batch++;
            }

            vector<string> res;
            for (int i = batch - 1; i >= 0; --i) {
                if (degree[i] == 0) {
                    int mini = INT_MAX, maxi = -1;
                    for (int j = 0; j < 26; ++j) {
                        if (batches[j] == i) {
                            mini = min(mini, mins[j]);
                            maxi = max(maxi, maxs[j]);
                        }
                    }

                    res.push_back(s.substr(mini, maxi - mini + 1));
                }
            }
            
            return res;
        }

    private:
        void dfs1(int v, vector<vector<bool>>& graph, stack<int>& s, vector<bool>& visited) {
            if (visited[v]) return;

            visited[v] = true;
            for (int i = 0; i < 26; ++i) {
                if (!graph[v][i] || visited[i]) continue;

                dfs1(i, graph, s, visited);
            }
            s.push(v);
        }
        
        void dfs2(int v, vector<vector<bool>>& graph, vector<int>& batches, int batch, vector<int>& degree) {
            if (batches[v] >= 0) {
                if (batches[v] != batch) {
                    degree[batches[v]]++;
                }
                return;
            }
            
            batches[v] = batch; 
            
            for (int i = 0; i < 26; ++i) {
                if (graph[i][v]) {
                    dfs2(i, graph, batches, batch, degree);
                }
            }
        }
};

