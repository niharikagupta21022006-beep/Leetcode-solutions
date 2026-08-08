class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string answer = "";
        for(int i = 0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }

            else{
                if(s[i] == st.top()){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }

        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }

        reverse(answer.begin(),answer.end());

        return answer;
    
    }
};