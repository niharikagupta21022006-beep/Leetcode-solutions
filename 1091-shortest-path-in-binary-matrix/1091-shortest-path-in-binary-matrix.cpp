class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.push({0, 0});

        int pathLength = 1;

        int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

        while (!q.empty()) {
            int current = q.size();

            for (int i = 0; i < current; i++) {
                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                if (r == m - 1 && c == n - 1) {
                    return pathLength;
                }

                for (int k = 0; k < 8; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                        grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            pathLength++;
        }

        return -1;
    }
};