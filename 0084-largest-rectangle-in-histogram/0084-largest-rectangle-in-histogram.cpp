class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int popedIndex;
        int width;
        int maxi = INT_MIN;
        int left;
        int area;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                popedIndex = st.top();
                st.pop();
                int height = heights[popedIndex];
                if (!st.empty()) {
                    width = i - st.top() - 1;
                }

                else {
                    width = i;
                }
                 area = height * width;
                 maxi = max(area, maxi);
            }
            st.push(i);

           
        }

        while(!st.empty()){
            popedIndex = st.top();
            st.pop();

            int right = heights.size();
            if(!st.empty()){
                left = st.top();
            }
            else{
                left = -1;
            }

            width = right-left -1;
            area =heights[popedIndex]*width;
            maxi = max(maxi,area);
        
        }
        return maxi;
    }
};