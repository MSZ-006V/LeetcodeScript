/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int slow = 0, fast = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[fast] == 0){
                swap(nums[slow], nums[fast]);
                slow++;
            }
            fast++;
        }
        fast = slow;
        for(int i = fast; i < nums.size(); ++i){
            if(nums[fast] == 1){
                swap(nums[slow], nums[fast]);
                slow++;
            }
            fast++;
        }
        
    }
};
// @lc code=end

