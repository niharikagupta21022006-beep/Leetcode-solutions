class Solution {
public:

    bool helper(int n){
        if( n <= 0){
            return false;
        }
        else if(n == 0){
            return true;
        }

        if(n == 1){
            return true;
        }

        else if(n % 3 != 0){
            return false;
        }

        else {
            return helper(n/3);
        }
    }
    bool isPowerOfThree(int n) {
        return helper(n);
    }
};