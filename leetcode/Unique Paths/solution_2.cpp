class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int K = m - 1;
        double res = 1.0;
        for (int i = 1; i <= K; ++i) {
            res = res * (N - K + i) / i;
        }
        
        return (int) res;
    }
};

/*
 * Time: O(m)
 * Space: O(1)
 * The number of steps taken is N = n + m - 2.
 * Hence we either N C m-1 or N C n-1.
 */