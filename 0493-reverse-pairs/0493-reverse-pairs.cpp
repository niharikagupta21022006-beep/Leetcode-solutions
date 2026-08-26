class Solution {
public:
    int merge(vector<int>& nums, long s, long mid, long e) {
        long long current = 0;
    
        long long j = mid + 1;
        for(int i = s;i<= mid;i++){
            while(j <= e && nums[i] > 2LL*nums[j]){
                j++;
            }

            current += j - (mid+1);
        }

        vector<int>temp;
        long i = s;
        j = mid+1;
        

        while(i <= mid && j<= e){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }

            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= e){
            temp.push_back(nums[j]);
            j++;
        }

        int k = s;
        for(int i = 0;i<temp.size();i++){
            nums[k] = temp[i];
            k++;
        }
        return current;
    }
    int helper(vector<int>& nums, long s, long e) {

        if (s >= e) {
            return 0;
        }

        long long mid = s + (e - s) / 2;

        long long left = helper(nums, s, mid);
        long long right = helper(nums, mid + 1, e);
        long long current = merge(nums, s, mid, e);
        long long count = left + right + current;
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};