class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> answer(nums.size(), -1);
        stack<int>st;
        for (int i = 0; i < 2*(nums.size())-1; i++) {
            int next = i % nums.size();
            
            while(!st.empty() && nums[st.top()]< nums[next]){
            
                answer[st.top()] = nums[next];
                st.pop();
                
    
            
                
            }
            st.push(next);
            
        }
        return answer;
    }
};