class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];

            // 打家劫舍2，环形，分别对有头房屋和没有头房屋进行分别讨论
            // 返回最大的价值那个就可以
    
            vector<int> dp(n, 0);
            dp[0] = nums[0];
            dp[1] = max(dp[0], nums[1]);
            for(int i = 2; i < n - 1; ++i){
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
    
            vector<int> dp1(n, 0);
            dp1[1] = nums[1];
            dp1[2] = max(dp1[1], nums[2]);
            for(int i = 3; i < n; ++i){
                dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            }
    
            // cout << dp1[n - 1] << ' ' << dp[n - 2];
            return max(dp1[n - 1], dp[n - 2]);
        }
    };
    