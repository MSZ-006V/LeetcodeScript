/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // 因为题目要求只用O(1)的空间，所以直接使用nums数组进行存储
        // 保证只有O(1)的空间复杂度
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            int index = abs(nums[i]) - 1; // 计算下标
            if(nums[index] < 0){ // 如果发现原来已经变成负的了，说明这个下标原来已经计算过了，说明这个数出现了两次，直接压入结果数组
                res.push_back(index + 1);
            }
            else{
                nums[index] *= -1; // 如果第一次遇到，就把它取个反，完全不影响的，因为计算时候用了abs()
            }
        }
        return res;
    }
};
// @lc code=end

