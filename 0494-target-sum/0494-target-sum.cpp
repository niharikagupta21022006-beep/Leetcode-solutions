class Solution {
public:
    int helper(vector<int>& nums, int target, int index, int currentSum) {
        if (index == nums.size()) {
            if (currentSum == target) {
                return 1;
            }

            else {
                return 0;
            }
        }

        int result = helper(nums, target, index + 1, currentSum + nums[index]) +
                     helper(nums, target, index + 1, currentSum - nums[index]);
        return result;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0, 0);
    }
};