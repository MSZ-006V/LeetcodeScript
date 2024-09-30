/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 相当于原数组有3段
        // 第一段和第三段都是有序的，中间第二段是无序的
        // 找到这个第二段的左右边界即可
        int length = nums.size();
        int begin = 0;
        int end = -1;
        int max = nums[0];
        int min = nums[length - 1];
        
        for(int i = 0; i < length; ++i){
            if(nums[i] < max){
                end = i;
            }
            else{
                max = nums[i];
            }

            if(nums[length - 1 - i] > min){
                begin = length - 1 - i;
            }
            else{
                min = nums[length - 1 - i];
            }
        }
        // cout << begin << ' ' << end;

        return end - begin + 1;

    }
};
// @lc code=end

