class Solution {
public:
    int helper(vector<int>& nums, int target, int index,
               vector<vector<int>>& memo) {

        int result = 0;
        if (target == 0) {
            return 1;
        }

        if (index == nums.size()) {
            return 0;
        }

        if (memo[index][target] != -1) {
            return memo[index][target];
        }
        if (nums[index] <= target) {
            result = helper(nums, target - nums[index], index + 1, memo) ||
                     helper(nums, target, index + 1, memo);
        }

        else if (nums[index] > target) {
            result = helper(nums, target, index + 1, memo);
        }

        memo[index][target] = result;
        return result;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));

        if (helper(nums, target, 0, memo)) {
            return true;
        }

        return false;
    }
};