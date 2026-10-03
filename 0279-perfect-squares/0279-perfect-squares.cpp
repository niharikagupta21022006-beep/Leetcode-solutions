class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,n+1);
        dp[0] = 0;

        for(int i = 1;i <= n;i++){
            for(int c = 1; c*c <= i;c++){
                dp[i] = min(dp[i],dp[i-c*c]+1);

            }
        }

        return dp[n];
    }
};