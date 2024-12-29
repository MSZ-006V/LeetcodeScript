/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         // 暴力方法
//         int n = matrix.size();
//         int m = matrix[0].size();
//         for(int i = 0; i < n; ++i){
//             if(matrix[i][0] <= target){
//                 if(matrix[i][m - 1] >= target){
//                     for(int j = 0; j < m; ++j){
//                         if(matrix[i][j] == target){
//                             return true;
//                         }
//                     }
//                 }
//             }
//         }
//         return false;

//     }
// };

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Z字形查找
        // tc O(m + n), sc O(1)
        // 在以matrix的左下角为左下角，右上角为（x，y）的矩形范围中查找
        // 行的范围是[x, m - 1]，列的范围是[0, y]
        // 如果matrix[x, y] > target，由于每一列的元素都是升序排列的，那么在当前的搜索矩阵中，所有位于第y列的元素都是严格大于target的，因此我们可以将它们全部忽略，y减少1
        // 如果matrix[x, y] < target，由于每一行的元素都是升序排列的，那么在当前的搜索矩阵中，所有位于第x行的元素都是严格小于target的，因此我们可以将它们全部忽略，x增加1

        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while(x < m && y >= 0){
            if(matrix[x][y] == target){
                return true;
            }
            if(matrix[x][y] > target){
                y--;
            }
            else{
                x++;
            }
        }

        return false;
    }
};
// @lc code=end

