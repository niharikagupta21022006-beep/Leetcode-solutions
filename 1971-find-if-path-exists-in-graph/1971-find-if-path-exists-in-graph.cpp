class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<int> adj[n];

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        queue<int> q;

        q.push(source);
        visited[source] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node]) {
                if (visited[neighbour] == 0) {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }

        if(visited[destination] == 1){
            return true;
        }

        return false;
    }
};