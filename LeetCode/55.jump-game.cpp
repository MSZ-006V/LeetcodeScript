/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        int index = 0;

        while(index <= cover){
            cover = max(cover, index + nums[index]);
            if(cover >= nums.size() - 1){
                return true;
            }
            index++;
        }

        return false;
    }
};
// @lc code=end

