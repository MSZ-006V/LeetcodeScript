class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // tc O(n^2) sc O(1)
        // 直接暴力解法，枚举所有的子数组，计算和，看是否能被k整除
        // 超时
        // int sum = 0;
        // int res = 0;
        // for(int right = 0; right < nums.size(); ++right){
        //     sum += nums[right];
        //     int temp_sum = sum;
        //     for(int left = 0; left <= right; ++left){
        //         if(temp_sum % k == 0){
        //             res++;
        //         }
        //         temp_sum -= nums[left];
        //     }
        // }

        // return res;

        // 根据同余定理
        // tc O(n) sc O(n)

        unordered_map<int, int> ht;
        ht[0] = 1;
        int sum = 0;
        int res = 0;
        for(auto num : nums){
            sum += num;
            int mod_result = (sum % k + k) % k; // 为了正常计算负数的余数
            res += ht[mod_result];
            ht[mod_result]++;
        }

        return res;
    }
};