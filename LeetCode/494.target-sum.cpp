/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 原方法的改进版本,时间复杂度O(n^2),空间复杂度O(n)
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if((abs(target) > total_sum) || ((target + total_sum) % 2 == 1)){
            return 0;
        }

        int target_v = (target + total_sum) / 2;
        vector<int> dp(target_v + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < nums.size(); ++i){
            for(int j = target_v; j >= nums[i]; --j){ 
            // 是逆序进行遍历的，
            // 因为如果顺序遍历会覆盖上次计算过的数据，导致出错，所以要使用逆序遍历
                dp[j] += dp[j - nums[i]];
            }
            // for(auto n : dp){ 可以看看打印出来的数组，会更容易理解
            //     cout << n << ' ';
            // }
            // cout << endl;
        }

        return dp[target_v];
    }
};
// @lc code=end

