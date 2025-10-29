class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            // leetcode 416很经典的题，背包问题，需要从后往前遍历，因为用的是一维数组节省空间
            // 所以必须要从后往前，如果从前往后就会覆盖掉上一层的结果
            // tc O(n^2), sc O(n)
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if(sum % 2) return false;
            int target = sum / 2;
    
            vector<int> dp(target + 1, 0);
            for(int i = 0; i < nums.size(); ++i){
                for(int j = target; j >= nums[i]; --j){
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
    
            return dp[target] == target? true : false;
        }
    };
    