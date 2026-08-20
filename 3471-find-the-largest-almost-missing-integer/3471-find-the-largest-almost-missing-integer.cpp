class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int freq[101] = {0};
        int count[101] = {0};
        int ans = -1;
        if (k >= 1 && k <= nums.size()) {
            for (int i = 0; i < k; i++) {
                freq[nums[i]]++;
            }

            for (int x = 0; x <= 100; x++) {
                if (freq[x] > 0) {
                    count[x]++;
                }
            }

            for (int i = k; i < nums.size(); i++) {
                freq[nums[i]]++;
                freq[nums[i - k]]--;

                for (int x = 0; x <= 100; x++) {
                    if (freq[x] > 0) {
                        count[x]++;
                    }
                }
            }

            for(int x = 0; x <=100;x++){
                if(count[x] == 1){
                    ans = x;

                }
            }
        }
        return ans;
    }
};