/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 对于矩阵大小n，只需要遍历x范围0~n/2，y范围0~(n+1)/2即可
        // 同时，下面这个方法是四个元素同时一起旋转，所以要暂存第一个元素，防止覆盖后丢失
        // 对于位置(i, j)，旋转后新位置的x值为j, 新位置的y值为n - 1 - i 
        // 第 i 行 = 第 n - 1 - i 列，第 j 列 = 第 j 行
        int n = matrix.size();
        for(int i = 0; i < n / 2; ++i){
            for(int j = 0; j < (n + 1) / 2; ++j){
                int temp = matrix[i][j];
                // 注意下面的规律，置换的前一个就是下一个被置换的，而且全部都满足规律
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};
// @lc code=end

