/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        for(int i = 0; i < nums.size(); ++i){
            if(ht.find(target - nums[i]) != ht.end()){
                return {i, ht[target - nums[i]]};
            }
            ht[nums[i]] = i;
        }
        
        return {};
    }
};
// @lc code=end

