class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> points(10001, 0);
        vector<int> dp(points.size());

        vector<int> freq(10001, 0);

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for (int i = 0; i < freq.size(); i++) {
            points[i] = i * freq[i];
        }
        if (points.size() == 1) {
            return points[0];
        }

        dp[0] = points[0];
        dp[1] = max(points[0], points[1]);

        for (int i = 2; i < points.size(); i++) {
            dp[i] = max(points[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[points.size() - 1];
    }
};