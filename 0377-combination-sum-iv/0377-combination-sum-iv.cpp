class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int c = 0; c < nums.size(); c++) {
                if (nums[c] <= i) {
                    dp[i] = dp[i] + dp[i - nums[c]];
                }
            }
        }

        return dp[target];
    }
};