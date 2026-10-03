class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);

        dp[0] = 1;

        for (long long c = 0; c < coins.size(); c++) {
            for (long long i = 1; i <= amount; i++) {
                if (coins[c] <= i) {
                    dp[i] = dp[i] + dp[i - coins[c]];
                }
            }
        }

       
        return dp[amount];
    }
};