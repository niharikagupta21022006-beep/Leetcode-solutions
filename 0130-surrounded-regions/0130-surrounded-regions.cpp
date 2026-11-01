class Solution {
public:

    void dfs(vector<vector<char>>& board,int s,int c){
        int m = board.size();
        int n = board[0].size();

        if(s < 0 || c <0 || s >= m|| c >=n){
            return;
        }

        if(board[s][c] != 'O'){
            return;
        }

        board[s][c] = '#';
        dfs(board,s-1,c);
        dfs(board,s+1,c);
        dfs(board,s,c-1);
        dfs(board,s,c+1);

    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int j = 0;j<n;j++){
            if(board[0][j] == 'O'){
                dfs(board,0,j);
            }
        }

        for(int j = 0;j<n;j++){
            if(board[m-1][j] == 'O'){
                dfs(board,m-1,j);
            }
        }

        for(int i = 0;i<m;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0);
            }
        }

        for(int i = 0;i<m;i++){
            if(board[i][n-1] == 'O'){
                dfs(board,i,n-1);
            }
        }

        for(int i =  0;i <m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }

                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};