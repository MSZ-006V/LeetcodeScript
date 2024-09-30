/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class MatrixSum{
private:
    vector<vector<int>> sum;
public:
    // 用于初始化二维前缀和，详细计算可以看
    // https://leetcode.cn/circle/discuss/UUuRex/
    MatrixSum(vector<string>& matrix){
        int m = matrix.size(), n = matrix[0].size();
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1)); // 初始化全为0, 而且恰好是多一行一列的
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i - 1][j - 1] + (matrix[i][j] & 1);
                // 'A'的ASCII最低位为1，'.'的最低位为0，所以有'A'就会变成1，否则变成0
            }
        }
    }
    
    // 返回左上角在 (r1,c1) 右下角在 (r2-1,c2-1) 的子矩阵元素和（类似前缀和的左闭右开）
    int query(int r1, int c1, int r2, int c2){
        return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
    }
};

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        // 
        // https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza/solutions/2392051/ji-bai-100cong-di-gui-dao-di-tui-dao-you-dxz5/
        // 记忆化搜索+递归+二维前缀和
        const int MOD = 1e9+7;
        MatrixSum ms(pizza);
        int m = pizza.size(), n = pizza[0].size();

        int memo[k][m][n];
        memset(memo, -1, sizeof(memo)); // -1 表示没有计算过

        function<int(int, int, int)> dfs = [&](int c, int i, int j){
            if(c == 0) return ms.query(i, j, m, n)?1:0;
            int &res = memo[c][i][j]; // 引用
            if(res != -1) return res; // 已经计算过了，直接结束递归
            res = 0;
            for(int j2 = j + 1; j2 < n; ++j2){
                if(ms.query(i, j, m, j2)){ // 切的这一刀有苹果
                    res = (res + dfs(c - 1, i, j2)) % MOD;
                }
            }
            for(int i2 = i + 1; i2 < m; ++i2){
                if(ms.query(i, j, i2, n)){ // 切的这一刀有苹果
                    res = (res + dfs(c - 1, i2, j)) % MOD;
                }
            }
            return res;
        };

        return dfs(k - 1, 0, 0);
    }
};
// @lc code=end

