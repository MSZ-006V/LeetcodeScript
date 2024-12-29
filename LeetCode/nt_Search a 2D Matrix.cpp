class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // tc O(log(mn)), sc O(1)
        // 实际上是二维二分查找，和一维二分查找比较类似，只不过多了一步
        // 需要把mid转换为二维数组中的行和列
        // 这个matrix在行上有序，在列上也有序，同时上一行的最后一个数一定小于下一行的第一个数，实际上整个数组是有序地
        // 参考leetcode74题，和lc240搜索二维矩阵ii，这个会有不同
        // 所以可以使用二分查找，这是最优方案
        // row行，col列
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int row = mid / cols, col = mid % cols;
            if(matrix[row][col] > target){
                right = mid - 1;
            }
            else if(matrix[row][col] < target){
                left = mid + 1;
            }
            else{
                return true;
            }
        }

        return false;
    }
};
