/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// 两种方法都可以，下面是正经的动态规划格式（2阶dp）
// 而第一种时间复杂度较小，第二种时间复杂度较大

// @lc code=start
// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int index = 0;
//         int lt = t.size();
        
//         for(int i = 0; i < lt; ++i){
//             if(t[i] == s[index]){
//                 index++;
//             }
//         }

//         return index == s.size()? true : false;
//     }
// };

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ls = s.size();
        int lt = t.size();
        vector<vector<int>> dp(ls + 1, vector<int>(lt + 1, 0));
        
        for(int i = 1; i < ls + 1; ++i){
            for(int j = 1; j < lt + 1; ++j){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[ls][lt] == ls? true : false;
    }
};
// @lc code=end

