class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int len = 2;len < n+2;len++){
            for(int i = 0;i+len < n+2;i++){
                int j = i+len;
                for(int k = i+1;k<j;k++){
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);

                }
            }
        }

        return dp[0][n+1];

    }
};