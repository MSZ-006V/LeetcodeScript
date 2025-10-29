class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // tc O(n^2), sc O(n)
        // 找的是子序列
        int n = nums.size();
        int res = 1;
        vector<int> dp(n, 1);

        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){ // 如果nums[j] < nums[i]，说明nums[i]可以作为nums[j]的下一个元素，于是判断
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};

// 二分查找方法，tc O(nlogn), sc O(n)
// 维护一个 dp 数组
// dp[i] 存储的是一个递增子序列的最小结尾元素，但它不一定是最终的 cnt 本身
// 1. 如果 nums[i] 比 dp 数组的最后一个元素大，说明可以直接扩展子序列，dp.push_back(nums[i])。
// 2. 否则，在 dp 数组中找到第一个不小于 nums[i] 的位置 idx，用 nums[i] 替换它，保证 dp 仍然是递增的。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        vector<int> dp;
        dp.push_back(nums[0]);

        for(int i = 1; i < n; ++i){
            if(dp.back() < nums[i]){
                cnt++;
                dp.push_back(nums[i]);
                continue;
            }

            int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[idx] = nums[i];
        }

        return cnt;
    }
};
    