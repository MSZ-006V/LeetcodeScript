/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // m is 0, n is 1
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(auto str : strs){
            int one_num = 0;
            for(auto c : str){
                if(c == '1'){
                    one_num++;
                }
            }
            int zero_num = str.size() - one_num;

            for(int i = n; i >= one_num; --i){
                for(int j = m; j >= zero_num; --j){
                    dp[i][j] = max(dp[i][j], dp[i - one_num][j - zero_num] + 1);
                }
            }
        }

        return dp[n][m];
    }
};
// @lc code=end

