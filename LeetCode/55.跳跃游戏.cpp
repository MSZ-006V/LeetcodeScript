/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    // 这题检测的是能否到达，45题跳跃游戏检测的是要跳几步
    // 所以这题只需要看覆盖范围就可以了，覆盖范围到最后了，就肯定能到
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size() == 1)
            return true;

        int index = 0;
        while(index <= cover){
            cover = max(index + nums[index], cover);
            if(cover >= nums.size() - 1)
                return true;
            index++;
        }
        return false;
    }
};
// @lc code=end

