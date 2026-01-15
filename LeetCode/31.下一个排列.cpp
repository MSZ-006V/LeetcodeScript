/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int n = nums.size();
        // for(int i = n - 1; i >= 0; --i){
        //     for(int j = n - 1; j > i; --j){
        //         if(nums[j] > nums[i]){
        //             // cout << nums[i] << nums[j] << endl;
        //             swap(nums[i], nums[j]); // j<i, 遇到nums[i] > nums[j], 就把两个元素交换
        //             reverse(nums.begin() + i + 1, nums.end()); // 把i+1后面的部分进行翻转
        //             return;
        //         }
        //     }
        // }
        // reverse(nums.begin(), nums.end());

        // 这题可以背诵，基本思路是从后往前，先找到第一个非降序的数，定为i
        // 然后从后往前，遍历j，找到第一个nums[i] < nums[j]的nums[j]数
        // 然后交换nums[i], nums[j]，然后把i + 1到末尾的数反转即可
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

