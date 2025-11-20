class Solution {
public:
    int numDistinct(string s, string t) {
        // tc: O(n * m), sc: O(n * m)
        // s = "caaat", t = "cat"
        // 每一步可以看为，dp[i][j]表示s的前i个字符中t的前j个字符的子序列个数
        // 比如对于c和c，那就是1
        // 对于c和ca，那就是0，所以一直后面也都是0
        // 对于ca和ca，还是1
        // 对于caa和ca，那就是用当前的caa加上之前的ca的数量，所以是2
        // 对于caa和cat，那也还是0
        // dp数组输出如下
        //     c a t
        //   1 0 0 0 
        // c 1 1 0 0 
        // a 1 1 1 0 
        // a 1 1 2 0 
        // a 1 1 3 0 
        // t 1 1 3 3 

        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n + 1; ++i){
            dp[i][0] = 1;
        }

        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < m + 1; ++j){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};
