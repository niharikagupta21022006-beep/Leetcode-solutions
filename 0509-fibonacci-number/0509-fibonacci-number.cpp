class Solution {
public:
    int fibonacci(int n,vector<int>& dp){
        if(n == 0){
            return 0;
        }

        if(n == 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        else{
            dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
            return dp[n];
        }
    }
        
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fibonacci(n,dp);
    }
};