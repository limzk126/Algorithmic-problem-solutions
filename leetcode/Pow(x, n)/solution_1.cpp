class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long power = n;
        if (power < 0) {
            power = -power, x = 1.0 / x;
        }
        
        while (power) {
            if (power & 1) {
                res *= x;
            }
            x *= x, power >>= 1;
        }
        
        return res;
    }
};

/*
 * This solution uses bit-manipulation.
 * Lets take for instance n = 13, its bit representation is 1101
 * We iterate from the right most bit.
 * For each iteration, we double x, since every succeeding bit is twice as large
 * as the current bit.
 * For each iteration, if we encounter a set bit, we multiply the current x to the result.
 * The idea is derived from the fact that x ^ (1101) = x ^ (1000) * x ^ (100) * x ^ (1)
 * Note: We need to use long long for power because absolute of -2147483648 cannot fit into int
 * as INT_MAX = 2147483648
 */