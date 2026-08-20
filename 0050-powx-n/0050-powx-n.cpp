class Solution {
public:
    double helper(double x, long long n) {
        double y;
        if (n == 0) {
            return 1;
        }

        if (n == 1) {
            return x;
        }

        if (n % 2 == 0) {
            if (n > 0) {
                y = helper(x, n / 2);
                return y * y;
            }

            else {
                y = helper(x, -n / 2);
                return 1 / (y * y);
            }
        }

        else {
            if (n > 0) {
                y = helper(x, n / 2);
                return x * y * y;
            }

            else {
                y = helper(x, -n / 2);
                return 1 / (x * y * y);
            }
        }
    }

    double myPow(double x, int n) { return helper(x, n); }
};