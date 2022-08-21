class Solution {
    public:
        string largestPalindromic(string num) {
            vector<int> cnt(10, 0);
            for (char c : num) {
                cnt[c - '0']++;
            }

            string lp, rp;
            for (int i = 9; i >= 0; --i) {
                while (cnt[i] > 1 && (i >= 1 || lp.size())) {
                    lp += '0' + i;
                    rp += '0' + i;
                    cnt[i] -= 2;
                }
            }
            for (int i = 9; i >= 0; --i) {
                if (cnt[i]) {
                    lp += i + '0'; break;
                }
            }

            reverse(begin(rp), end(rp));
            return lp + rp;
        }
};
