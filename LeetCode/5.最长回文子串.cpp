/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 0;
        int left = 0, right = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < n; ++j){
                if(s[i] == s[j]){
                    if(j - i <= 1){
                        dp[i][j] = true;
                    }
                    else if(dp[i + 1][j - 1]){
                        dp[i][j] = true;
                    }
                }
                if(dp[i][j] && j - i + 1 > max_len){
                    max_len = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
        cout << max_len;
        return s.substr(left, max_len);
    }
};
// @lc code=end

