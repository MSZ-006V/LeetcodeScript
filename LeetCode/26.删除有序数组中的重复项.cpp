/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> set;
        // for(auto num : nums){
        //     set.insert(num);
        // }
        // int index = 0;
        // for(auto num : set){
        //     nums[index++] = num;
        // }
        // return set.size();
        int slow = 1, fast = 1;
        while(fast < nums.size()){
            if(nums[fast - 1] != nums[fast]){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
// @lc code=end

