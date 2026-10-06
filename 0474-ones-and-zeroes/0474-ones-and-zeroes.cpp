class Solution {
public:
    int helper(vector<string>& strs, vector<vector<vector<int>>>& memo,
               int index, int m, int n) {
        if (index == strs.size()) {
            return 0;
        }

        if (memo[index][m][n] != -1) {
            return memo[index][m][n];
        }
        int zero = 0;
        int ones = 0;

        for (int j = 0; j < strs[index].size(); j++) {

            if (strs[index][j] == '0') {
                zero++;
            }

            else {
                ones++;
            }
        }

        int take = 0;
        int notTake = 0;

        if (zero <= m && ones <= n) {
            take = 1 + helper(strs, memo, index + 1, m - zero, n - ones);

            notTake = helper(strs, memo, index + 1, m, n);
        }

        if(zero > m || ones > n){
            notTake = helper(strs,memo,index+1,m,n);
        }

        int ans = max(take, notTake);
        memo[index][m][n] = ans;

        return ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>memo(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(strs,memo,0,m,n);
    }
};