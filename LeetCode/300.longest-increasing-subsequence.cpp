/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
// 1. 核心思想：贪心 (Greedy)
// 这个算法的本质是：为了让递增子序列尽可能长，我们需要让序列中每一个位置的数字尽可能小。

// res 数组的含义：res[i] 表示长度为 i+1 的上升子序列中，末尾元素的最小值。

// 为什么可以二分？：因为 res 数组在整个过程中始终保持严格递增。

// 策略：

// 如果当前数字 num 比 res 所有的数都大，说明能接在后面，让序列更长（push_back）。

// 如果 num 比较小，它虽然不能增加长度，但它可以替换掉第一个大于等于它的数。这样我们就“优化”了那个位置的最小值，为后面接更多的数字创造了空间。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // tc O(nlogn), sc O(n)
        vector<int> res;
        for(auto num : nums){
            // 直接在结果数组中查找
            auto it = ranges::lower_bound(res.begin(), res.end(), num);
            if(it == res.end()){ // 没找到就说明这是一个新的可以递增的序列
                res.push_back(num);
            }
            else{ // 如果找到修改res，可以减小数组每一个元素递增之间的范围，得到更大的递增区间
                *it = num;
            }
        }
        return res.size();

        // tc O(n^2), sc O(n)
        // int n = nums.size();
        // vector<int> dp(n, 1);

        // for(int i = 1; i < n; ++i){
        //     for(int j = 0; j < i; ++j){
        //         if(nums[i] > nums[j]){
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        // }

        // return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

