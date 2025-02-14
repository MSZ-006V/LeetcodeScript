/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // # 相当于01背包问题，重量和价值数组相同，都为nums
        // # 背包最大容量为target，即数组总和的一半
        // # dp[i]的意义为在空间i下面的最大价值，当dp[i] = i时，即代表可以放入这么多的价值的数
        // # 即代表可以分为一个子集，使得两个子集的元素和相等
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;

        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < nums.size(); ++i){
            for(int j = target; j > nums[i] - 1; --j){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return dp[target] == target? true : false;
    }
};
// @lc code=end

