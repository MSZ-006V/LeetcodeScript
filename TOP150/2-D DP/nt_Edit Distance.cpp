class Solution {
public:
    int minDistance(string word1, string word2) {
        // 插入和删除是相同的
        int n = word1.size();
        int m = word2.size();

        // 因为要访问到dp[i][j - 1], 所以i和j要从1开始
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n + 1; ++i){
            dp[i][0] = i;
        }
        for(int j = 0; j < m + 1; ++j){
            dp[0][j] = j;
        }

        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < m + 1; ++j){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    // dp[i - 1][j - 1]代表删除或修改，dp[i - 1][j]代表在word1增加一个，dp[i][j - 1]代表word2删除一个
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        // for(int i = 0; i < n + 1; ++i){
        //     for(int j = 0; j < m + 1; ++j){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        return dp[n][m];
    }
};
