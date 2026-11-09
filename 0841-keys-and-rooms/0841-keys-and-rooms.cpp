class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> visited(n, 0);
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < rooms[current].size(); i++) {
                if (visited[rooms[current][i]] == 0) {
                    visited[rooms[current][i]] = 1;
                    q.push(rooms[current][i]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                return false;
            }
        }

        return true;
    }
};