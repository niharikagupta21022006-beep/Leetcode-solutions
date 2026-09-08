class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>answer;
        for(int i = 0;i <candies.size();i++){
            
            int sum = candies[i] + extraCandies;
            int maxi = *max_element(candies.begin(),candies.end());

            if(sum >= maxi){
                answer.push_back(true);
            }

            else{
                answer.push_back(false);
            }
        }
        return answer;
        
    }
};