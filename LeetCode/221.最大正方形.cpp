/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp(i,j) 表示以 (i,j) 为右下角，且只包含 1 的正方形的边长最大值
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int max_val = 0;
        for(int i = 0; i < n; ++i){
            if(matrix[i][0] == '1'){
                dp[i][0] = 1;
                max_val = 1; // 如果初始化过程中有1，则最小的边长至少是1
            }
        }
        for(int i = 0; i < m; ++i){
            if(matrix[0][i] == '1'){
                dp[0][i] = 1;
                max_val = 1;
            }
        }
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                if(matrix[i][j] == '1'){
                    // 因为记录的是正方形边长最大值，所以要考虑周围的三个点（左，左上，上）
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                else{
                    dp[i][j] = 0;
                }
                if(dp[i][j] > max_val){
                    max_val = dp[i][j];
                }
            }
        }
        
        return max_val*max_val;
    }
};
// @lc code=end

