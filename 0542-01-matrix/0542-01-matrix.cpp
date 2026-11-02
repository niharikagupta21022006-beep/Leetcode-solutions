class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m,vector<int>(n,-1));

        queue<pair<int,int>>q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            if(r > 0 && dist[r-1][c] == -1){
                dist[r-1][c] = dist[r][c] + 1;
                q.push({r-1,c});
            }

            
            if(r < m-1 && dist[r+1][c] == -1){
                dist[r+1][c] = dist[r][c] + 1;
                q.push({r+1,c});
            }

            
            if(c > 0 && dist[r][c-1] == -1){
                dist[r][c-1] = dist[r][c] + 1;
                q.push({r,c-1});
            }

            
            if(c < n-1 && dist[r][c+1] == -1){
                dist[r][c+1] = dist[r][c] + 1;
                q.push({r,c+1});
            }

            
        }
        return dist;

    }
};