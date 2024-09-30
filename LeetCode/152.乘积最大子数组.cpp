/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return nums[0];
        }

        // 需要维护3个数组，一个是dp数组，另外两个是max和min
        vector<double> dp = vector<double>(n, 0);
        vector<double> maxDp = vector<double>(n, 0);
        vector<double> minDp = vector<double>(n, 0);
        dp[0] = nums[0];
        maxDp[0] = nums[0];
        minDp[0] = nums[0];
        
        for(int i = 1; i < n; ++i){
            maxDp[i] = max(max(maxDp[i - 1] * nums[i], (double)nums[i]), minDp[i - 1] * nums[i]);
            minDp[i] = min(min(minDp[i - 1] * nums[i], (double)nums[i]), maxDp[i - 1] * nums[i]);
            dp[i] = max(dp[i - 1], maxDp[i]);
        }
        // 对于{-1, -2, -3, -4}这个数组，对以下标i结尾的子数组，求最大乘积的过程如下, 表示为{最大，最小}
        // 对于i = 0, {-1, -1}
        // 对于i = 1, {2, -2}, -2单独自己就是最小的
        // 对于i = 2, {6(-2*-3), -6(2*-3)}
        // 对于i = 3, {24(-6*-4), -24(6*-4)}
        // 所以可以看到，必须要同时记录最大和最小的数，因为不能保证上一个最小的数在乘上下一个负数后，就变成最大的了
        // 同时还要注意，有可能最小的子数组或者最大的自数字，就是单独的某一个数
        // 所以需要对maxDP[i - 1] * nums[i], minDP[i - 1] * nums[i], nums[i] 这三个数取max和min
        // 同时再使用DP数组进行记录（也可以不用），就能够得出最终答案了
        return dp[n - 1];
    }
};
// @lc code=end

