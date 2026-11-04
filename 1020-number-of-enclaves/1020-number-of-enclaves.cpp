class Solution {
public:

    void dfs(int s,int c,vector<vector<int>>& grid,vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();

        if(s < 0 || c < 0 ||  s >= m || c >= n){
            return ;
        }

        if(grid[s][c] == 0 || visited[s][c] == 1){
            return;
        }

        visited[s][c] = 1;

        dfs(s-1,c,grid,visited);
        dfs(s+1,c,grid,visited);
        dfs(s,c-1,grid,visited);
        dfs(s,c+1,grid,visited);

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int j = 0; j<n;j++){
            if(grid[0][j] == 1 && visited[0][j] == 0){
                dfs(0,j,grid,visited);
            }
        }

        for(int j = 0; j < n;j++){
            if(grid[m-1][j] == 1 && visited[m-1][j] == 0){
                dfs(m-1,j,grid,visited);
            }
        }

        for(int i = 0;i < m ;i++){
            if(grid[i][0] == 1 && visited[i][0] == 0){
                dfs(i,0,grid,visited);
            }
        }

        for(int i = 0;i < m;i++){
            if(grid[i][n-1] == 1 && visited[i][n-1] == 0 ){
                dfs(i,n-1,grid,visited);
            }
        }
        int enclave = 0;

        for(int i = 0;i < m;i++){
            for(int j = 0;j <n;j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    enclave++;
                }

            }
        }
        return enclave;
    }
};