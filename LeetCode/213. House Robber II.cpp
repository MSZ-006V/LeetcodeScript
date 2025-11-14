class Solution {
public:
    int rob_f(vector<int> nums){ // 这里不能用引用，因为需要对数组进行切片
        if(nums.size() == 1) return nums[0];

        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int t1 = rob_f(vector<int>(nums.begin(), nums.end() - 1));
        int t2 = rob_f(vector<int>(nums.begin() + 1, nums.end()));
        return max(t1, t2);
    }
};