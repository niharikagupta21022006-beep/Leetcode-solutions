class Solution {
public:
    string toLowerCase(string s) {
        string answer;
        for(int i = 0;i <s.length();i++){
            answer.push_back(tolower(s[i]));
        }
        return answer;
    }
};