class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& color, int col) {

        color[node] = col;

        for(int neighbor : adj[node]) {

            if(color[neighbor] == -1) {
                if(dfs(neighbor, adj, color, 1 - col) == false) {
                    return false;
                }
            }
            else if(color[neighbor] == col) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        for(auto it : dislikes) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n + 1, -1);

        for(int i = 1; i <= n; i++) {

            if(color[i] == -1) {
                if(dfs(i, adj, color, 0) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};