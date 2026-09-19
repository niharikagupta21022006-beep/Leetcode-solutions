class Solution {
public:
    int xorOperation(int n, int start) {
        int answer = 0;
        vector<int>nums(n,0);
        for(int i = 0;i<n;i++){
            nums[i] = start + 2*i;
            answer = answer^nums[i];
        }
        return answer;
    }
};