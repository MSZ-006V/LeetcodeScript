/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    bool check(vector<vector<int>>& matrix, int n, int k, int mid){
        int i = n - 1;
        int j = 0;
        int num = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] <= mid){
                // 统计小于等于k的元素个数
                num += i + 1;
                j++;
            }
            else{
                i--;
            }
        }
        // 如果数目大于等于k，说明右边right太大了，需要缩小
        // 如果小于k，说明左边left太小了，需要扩大一下
        return num >= k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // time complexity is O(nlogn), space complexity is O(1)
        // 基于二分查找的进阶版练习，建议看官方题解
        // https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/description/
        // 思维比较巧妙，但是也是二分查找类型的模版题，理解check函数就可以了，其实就是根据特性
        // 统计矩阵里面比k小的元素个数，因为题目找数组中第k小的元素，所以这个元素是全部数组中排倒数第k个
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(matrix, n, k, mid)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

