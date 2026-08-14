class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> answer(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            int next = (i + 1) % nums.size();
            int count = 0;

            while (count < nums.size() - 1) {

                if (nums[next] > nums[i]) {
                    answer[i] = nums[next];
                    break;
                } else {

                    next = (next + 1) % nums.size();
                    count++;
                }
            }
        }
        return answer;
    }
};