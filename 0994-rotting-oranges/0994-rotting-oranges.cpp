class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int time = 0;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        while (!q.empty()) {
            int current = q.size();
            for (int i = 0; i < current; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if (r > 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    q.push({r - 1, c});
                    fresh--;
                }

                if (r < m - 1 && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    q.push({r + 1, c});
                    fresh--;
                }

                if (c > 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    q.push({r, c - 1});
                    fresh--;
                }

                if (c < n - 1 && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    q.push({r, c + 1});
                    fresh--;
                }
            }

            if (!q.empty()) {
                time++;
            }
        }

        if (fresh > 0) {
            return -1;
        }
        return time;
    }
};