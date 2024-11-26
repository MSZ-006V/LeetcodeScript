/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int left = 0, right = nums.size() - 1;
        // while(left < right){
        //     if(nums[left] == 0){
        //         swap(nums[right], nums[left]);
        //         right--;
        //     }
        //     left++;
        // }
        int slow = 0;
        for(int fast = 0; fast < nums.size(); ++fast){
            if(nums[fast] != 0){
                swap(nums[fast], nums[slow]);
                slow++;
            }
        }
        for(int i = slow; i < nums.size(); ++i){
            nums[i] = 0;
        }
    }
};
// @lc code=end

