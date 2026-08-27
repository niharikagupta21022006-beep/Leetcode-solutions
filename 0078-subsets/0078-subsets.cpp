class Solution {
public:
    void solve(vector<int> nums, int index, vector<vector<int>> &answer,vector<int> &current) {
        if (index >= nums.size()) {
            answer.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        solve(nums,index+1,answer,current);
        current.pop_back();

        solve(nums,index+1,answer,current);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> current;
        current = {};

        solve(nums, 0, answer, current);
        return answer;
    }
};