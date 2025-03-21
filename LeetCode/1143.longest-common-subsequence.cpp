/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
// dp = [[0] * (len(text2) + 1) for _ in range(len(text1) + 1)]
// result = 0

// for i in range(1, len(text1) + 1):
//     for j in range(1, len(text2) + 1):
//         if text1[i - 1] == text2[j - 1]:
//             dp[i][j] = dp[i - 1][j - 1] + 1
//         else:
//             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
//         if dp[i][j] > result:
//             result = dp[i][j]

// # print(dp)

// return result
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 很经典的一道动态规划算法，计算最长公共子序列，时间复杂度O(n * m)
        int t1 = text1.size();
        int t2 = text2.size();
        vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, 0));
        int result = 0;

        for(int i = 1; i < t1 + 1; ++i){
            for(int j = 1; j < t2 + 1; ++j){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if(dp[i][j] > result) result = dp[i][j];
            }
        }

        return result;
    }
};
// @lc code=end

def fib(n, cache={}):
    if n in cache:
        return cache[n]
    if n <= 1:
        return n
    cache[n] = fib(n - 1, cache) + fib(n - 2, cache)
    return cache[n]