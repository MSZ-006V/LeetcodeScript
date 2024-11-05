/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 */

// @lc code=start
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1000000007;
        int ans = 0;
        vector<int> f(high + 1); 
        f[0] = 1; 
        for (int i = 1; i <= high; i++) {
            if (i >= zero) f[i] = f[i - zero];
            if (i >= one)  f[i] = (f[i] + f[i - one]) % MOD;
            if (i >= low)  ans = (ans + f[i]) % MOD;
        }
        return ans;
    }
};
// @lc code=end

