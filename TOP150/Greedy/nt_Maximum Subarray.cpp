class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // tc: O(n), sc: O(1)
        int res = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            res = max(res, sum);
            if(sum < 0){
                sum = 0;
            }
        }

        return res;
    }
};
