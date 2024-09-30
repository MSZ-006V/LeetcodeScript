/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 */

// @lc code=start
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // 本质上和377是一个类型的
        vector<long long> dp(high + 1);
        long long mod = 1000000007;
        dp[0] = 1;
        for(int i = 0; i < high + 1; ++i){
            if(i - zero >= 0){
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            }
            if(i - one >= 0){
                dp[i] = (dp[i] + dp[i - one]) % mod;
            }
        }

        long long sum = 0;
        for(int i = low; i <= high; ++i){
            sum = (sum + dp[i]) % mod;
        }
        return sum;
    }
};
// @lc code=end

