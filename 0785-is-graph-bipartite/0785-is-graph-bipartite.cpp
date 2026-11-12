class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int col) {

        color[node] = col;

        for(int neighbor : graph[node]) {

            if(color[neighbor] == -1) {
                if(dfs(neighbor, graph, color, 1 - col) == false) {
                    return false;
                }
            }
            else if(color[neighbor] == col) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {

            if(color[i] == -1) {
                if(dfs(i, graph, color, 0) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};