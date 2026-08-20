class Solution {
public:

    bool helper(int n){
        if(n <= 0){
            return false;
        }

        if(n == 1){
            return true;
        }

        if(n % 4 != 0){
            return false;
        }

        else{
            return helper(n/4);
        }
    }
    bool isPowerOfFour(int n) {
       return helper(n) ;
    }
};