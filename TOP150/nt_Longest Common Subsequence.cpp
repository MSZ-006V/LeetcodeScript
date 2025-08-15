class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // tc O(n^2), sc O(n)
        // leetcode 1143
        int t1 = text1.size();
        int t2 = text2.size();
        int res = 0;

        vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, 0));

        for(int i = 1; i < t1 + 1; ++i){
            for(int j = 1; j < t2 + 1; ++j){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                
                if(dp[i][j] > res){
                    res = dp[i][j];
                }
            }
        }

        return res;
    }
};
    