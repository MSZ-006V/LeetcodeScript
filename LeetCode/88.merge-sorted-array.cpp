/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // tc O(m + n), tc O(1)
        // 双指针倒序法，而且是原地排序，不需要额外空间
        // nums1的空间大小就是m + n，双指针倒序排序可以保证不会有覆盖问题
        int p1 = m - 1;
        int p2 = n - 1;
        int index = m + n - 1;

        while(p2 >= 0){
            if(p1 >= 0 && nums1[p1] > nums2[p2]){
                nums1[index--] = nums1[p1--];
            }
            else{
                nums1[index--] = nums2[p2--];
            }
        }
    }
};
// @lc code=end

