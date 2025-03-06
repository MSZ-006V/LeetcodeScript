/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(); 
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for(int i = 0; i < n1 + 1; ++i){
            dp[i][0] = i;
        }
        for(int j = 0; j < n2 + 1; ++j){
            dp[0][j] = j;
        }


        // 虽然是三种操作，替换，增加，删除，但是由于增加和删除是相同的操作
        // 比如ro和r，增加一个o和删去一个o，操作数一样，结果一样，所以完全可以等价
        for(int i = 1; i < n1 + 1; ++i){
            for(int j = 1; j < n2 + 1; ++j){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }

        return dp[n1][n2];
    }
};
// @lc code=end

