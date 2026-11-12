class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited,
             vector<int>& pathVisited) {

        visited[node] = 1;
        pathVisited[node] = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i];

            if (pathVisited[neighbour] == 1) {
                return true;
            }

            if (visited[neighbour] == 0) {
                if (dfs(neighbour, adj, visited, pathVisited)) {
                    return true;
                }
            }
        }

        pathVisited[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for (auto it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adj, visited, pathVisited)) {
                    return false;
                }
            }
        }

        return true;
    }
};