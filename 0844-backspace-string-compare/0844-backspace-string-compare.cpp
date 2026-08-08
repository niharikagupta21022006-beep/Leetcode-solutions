class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;

        for(int i = 0;i<s.length();i++){
            if(s[i] == '#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }
            else{
                st1.push(s[i]);
            }
        }

        for(int j = 0;j<t.length();j++){
            if(t[j] == '#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }

            else{
                st2.push(t[j]);
            }
        }

        if(st1 == st2){
            return true;
        }

        return false;
    }
};