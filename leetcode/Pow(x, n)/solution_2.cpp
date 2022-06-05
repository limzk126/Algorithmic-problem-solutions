class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long power = n;
        if (power < 0) {
            power = -power, x = 1.0 / x;
        }
        while (power) {
            if (power % 2 == 1) {
                res *= x;
                power -= 1;
            } else {
                x *= x;
                power /= 2;
            }
        }
        
        return res;
    }
};

/*
 * Visualize using tree. For example:
 * 2 ^ 20
 * 2 ^ 10 -- 2 ^ 10
 * 2 ^ 5 -- 2 ^ 5 -- 2 ^ 5 -- 2 ^ 5
 * ...
 */