class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        vector<int> ans;

        function<bool(int)> dfs = [&](int node) {
            visited[node] = 1;
            pathVisited[node] = 1;

            for (int neighbor : adj[node]) {

                if (visited[neighbor] == 0) {
                    if (dfs(neighbor) == false) {
                        return false;
                    }
                } else if (pathVisited[neighbor] == 1) {
                    return false;
                }
            }

            pathVisited[node] = 0;
            ans.push_back(node);

            return true;
        };

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(i) == false) {
                    return {};
                }
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};