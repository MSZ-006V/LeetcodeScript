class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            // leetcode 152, tc O(n), sc O(n)
            int n = nums.size();
            if(n == 0){
                return 0;
            }
            else if(n == 1){
                return nums[0];
            }
    
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
    
            return dp[n - 1];
        }
    };
    