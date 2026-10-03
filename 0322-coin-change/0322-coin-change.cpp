class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        

        dp[0] = 0;
        for(int i = 0;i <= amount;i++){
            for(int c = 0;c < coins.size();c++){
                if(coins[c] <= i){
                    dp[i] = min(dp[i],dp[i-coins[c]]+1);
                }
            }

        }
        if(dp[amount] == amount+1){
            return -1;
        }

        return dp[amount];
    }
};