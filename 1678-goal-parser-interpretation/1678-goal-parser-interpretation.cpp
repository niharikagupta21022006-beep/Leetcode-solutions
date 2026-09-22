class Solution {
public:
    string interpret(string command) {
        string answer;
        for(int i = 0;i <command.length();){
            if(command[i] == 'G'){
                answer +=('G');
                i++;
            }

            else if(command[i] == '(' && command[i+1] == ')'){
                answer += ('o');
                i+=2;
            }
            
            else if(command[i] == '(' && command[i+1] == 'a'){
                answer +=("al");
                i+=4;
            }
        }
        return answer;
    }
};