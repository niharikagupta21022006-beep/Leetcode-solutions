class Solution {
public:
    bool helper(int n){
        if(n == 1){
            return true;
        }

        if(n <= 0){
            return false;
        }

        else if(n % 2 != 0){
            return false;
        }

        else {
            return helper(n/2);
        }
    }
    

    bool isPowerOfTwo(int n) {
        return helper(n);
    }
};