class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& graph,
             vector<int>& color) {
        color[node] = col;
        for (int i = 0; i < graph[node].size(); i++) {
            int neighbour = graph[node][i];
            if (color[neighbour] == -1) {
                if (dfs(neighbour, 1 - col, graph, color) == false) {
                    return false;
                };
            }

            if (color[neighbour] != -1) {
                if (color[neighbour] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, graph, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};