/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.size();
        int lt = t.size();

        vector<vector<int>> dp(ls + 1, vector<int>(lt + 1, 0));
        for(int i = 0; i < ls + 1; ++i){
            dp[i][0] = 1;
        }
        for(int i = 1; i < ls + 1; ++i){
            for(int j = 1; j < lt + 1; ++j){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for(auto r : dp){
            for(auto e : r){
                cout << e << ' ';
            }
            cout << endl;
        }

        return dp[ls][lt];

    }
};
// @lc code=end

