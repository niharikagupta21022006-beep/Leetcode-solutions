class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& adj, vector<int>& color) {
        color[node] = col;

        for (int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i];

            if (color[neighbour] == -1) {
                if (dfs(neighbour, 1 - col, adj, color) == false) {
                    return false;
                }
            }

            else if(color[neighbour] == color[node]){
                return false;
            }

            
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, adj, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};