/*
 * @lc app=leetcode id=2389 lang=cpp
 *
 * [2389] Longest Subsequence With Limited Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end()); // 只需要对nums排序，然后计算每个元素累加和就可以
        // 因为题目要求的是子序列，不是连续子序列
        int sum = 0;
        for(auto& num:nums){
            sum += num;
            num = sum;
        }

        vector<int> result;
        for(auto query:queries){
            int res = ranges::upper_bound(nums.begin(), nums.end(), query) - nums.begin();
            result.push_back(res);
        }
        return result;
    }
};
// @lc code=end

