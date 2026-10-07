class Solution {
public:

    int helper(vector<int>& stones,int index,int target,vector<vector<int>>&memo){
        int result = 0;

        if(target == 0){
            return 0;
        }
        
        if(index == stones.size()){
            return 0;
        }

        if(memo[index][target] != -1){
            return memo[index][target];
        }
        int take = 0;
        int notTake = 0;

        if(target >= stones[index]){
             take = stones[index]+ helper(stones,index+1,target-stones[index],memo); 
             notTake =  helper(stones,index+1,target,memo);
        }

        if(target < stones[index]){
            notTake = helper(stones,index+1,target,memo);
        }

        result = max(take,notTake);

        memo[index][target] = result;
        return result;
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i = 0;i <stones.size();i++){
            sum = sum + stones[i];
        }

        int target = sum/2;

        vector<vector<int>>memo(stones.size(),vector<int>(target+1,-1));
        int best =  helper(stones,0,target,memo);
        return sum - 2*best;


    }
};