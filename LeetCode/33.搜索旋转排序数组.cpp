/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    // 由于是旋转排序数组，那么这个数组一定可以分为前后两个部分
    // 前面一部分的所有数都大于后一部分的数，也有nums[0] > nums[n - 1]
    // 通过这个性质，判断left ~ mid - 1是有序数组，还是mid + 1 ~ right是有序数组
    // 判断完哪边是有序数组后，再在有序数组中继续搜索
    int binary_search(vector<int>& nums, int target){
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            // 下面target和nums[mid]之间都是不等于号，因为上面if已经比较过了，没必要重复写
            // 但是nums[0], nums[n - 1]还是要写小于等于或者大于等于的
            if(nums[0] <= nums[mid]){
                if(nums[0] <= target && target < nums[mid]){ 
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[n - 1]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return nums[0] == target?0:-1;
        int index = binary_search(nums, target);
        return index;
    }
};
// @lc code=end

