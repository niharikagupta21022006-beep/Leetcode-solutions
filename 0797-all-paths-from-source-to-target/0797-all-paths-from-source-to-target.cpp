class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path,
             vector<vector<int>>& ans, int n) {
        if (node == n - 1) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < graph[node].size(); i++) {
            path.push_back(graph[node][i]);
            dfs(graph, graph[node][i], path, ans, n);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;
        int n = graph.size();
        path.push_back(0);

        dfs(graph, 0, path, ans, n);
        return ans;
    }
};