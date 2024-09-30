/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
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

