/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int quicksort(vector<int>& nums, int l, int r, int k){
        if(l == r) return nums[k];
        int partition = nums[l], i = l - 1, j = r + 1;
        while(i < j){
            do i++; while(nums[i] < partition);
            do j--; while(nums[j] > partition);
            if(i < j) swap(nums[i], nums[j]);
        }
        // 此时的数组以partition分成两个部分，左边部分是[l, j], 右边是[j + 1, r]
        // 左边部分的所有元素都小于右边的所有元素，如果k<=j的话，那就说明是要找数组中第k小的元素，所以就往左边遍历
        // 如果k>j的话，那就说明是要找数组中第k大的元素，那就往右边遍历
        if(k <= j) return quicksort(nums, l, j, k); 
        else return quicksort(nums, j + 1, r, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        // 这个快速排序排序出来是增序的，从小到大
        int n = nums.size();
        // [1,2,3,4,5]数组中，第2大的数是4，位置就是5（数组长度） - 2（第2大） = 3, 4的数组下标也就是3
        // [1,2,3,4,5]数组中，第2小的数是2，位置就是2, 2的数组下标也就是2
        return quicksort(nums, 0, n - 1, n - k); // 参数是n - k，那么就是找数组中第k大
        //return quicksort(nums, 0, n - 1, k - 1); // 如果参数是k - 1，那么就是找数组中第k小
    }
};
// @lc code=end

