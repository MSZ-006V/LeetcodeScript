/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int max_len = 1, left = 0;
        list<int> list1;
        list<int> list2;
        
        for(int i = 0; i < nums.size(); ++i){
            while(!list1.empty() && nums[list1.back()] < nums[i]){ 
                list1.pop_back(); // 递减序列，维护最大值
            }
            while(!list2.empty() && nums[list2.back()] > nums[i]){
                list2.pop_back(); // 递增序列，维护最小值
            }
            list1.push_back(i);
            list2.push_back(i);
            // list1 提供最大值，list2提供最小值
            while(!list1.empty() && !list2.empty() && abs(nums[list1.front()] - nums[list2.front()] > limit)){
                if(nums[list1.front()] == nums[left]) list1.pop_front();
                if(nums[list2.front()] == nums[left]) list2.pop_front();
                left++;
            }

            max_len = max(max_len, i - left + 1);
        }

        return max_len;
    }
};
// @lc code=end

