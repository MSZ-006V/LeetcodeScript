/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; ++i){
            if(matrix[i][0] <= target){
                if(matrix[i][m - 1] >= target){
                    for(int j = 0; j < m; ++j){
                        if(matrix[i][j] == target){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

