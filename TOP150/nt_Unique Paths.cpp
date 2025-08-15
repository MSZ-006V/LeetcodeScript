class Solution {
public:
    int uniquePaths(int m, int n) {\
        // tc O(n^2), sc O(n^2)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; ++i){
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; ++j){
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // tc O(n^2), sc O(n)
        // 空间优化了，每一行进行遍历，从下往上，从右往左
        vector<int> dp(n, 1);
        
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[j] += dp[j + 1];
            }
        }
        
        return dp[0];
    }
};
    