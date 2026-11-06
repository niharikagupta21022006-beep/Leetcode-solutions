class Solution {
public:
    bool dfs(int s, int c, vector<vector<int>>& grid2,
             vector<vector<int>>& grid1, vector<vector<int>>& visited) {
        int m = grid2.size();
        int n = grid2[0].size();
        if (s < 0 || c < 0 || s >= m || c >= n) {
            return true;
        }

        if (grid2[s][c] == 0 || visited[s][c] == 1) {
            return true;
        }

        visited[s][c] = 1;

        bool valid = true;

        if (grid2[s][c] == 1 && grid1[s][c] == 0) {
            valid = false;
        }

        valid = dfs(s - 1, c, grid2, grid1, visited) && valid;
        valid = dfs(s + 1, c, grid2, grid1, visited) && valid;
        valid = dfs(s, c - 1, grid2, grid1, visited) && valid;
        valid = dfs(s, c + 1, grid2, grid1, visited) && valid;

        return valid;
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && visited[i][j] == 0) {
                    if (dfs(i, j, grid2, grid1, visited)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};