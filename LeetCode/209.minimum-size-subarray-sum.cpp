/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 使用前缀和+二分查找
        vector<int> prefix_sum;
        prefix_sum.push_back(0); // 在开头插入一个0方便进行计算，方便计算数组第一位的前缀和
        int sum = 0; 
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            prefix_sum.push_back(sum); // 首先计算前缀和
        }

        int min_len = prefix_sum.size();
        for(int i = 1; i < prefix_sum.size(); ++i){
            int search_target = target + prefix_sum[i - 1]; // 每次新得到一个search_target进行二分查找
            auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), search_target); // 二分查找
            if(it != prefix_sum.end()){ // 如果找到就进行判断
                min_len = min(min_len, int((it - prefix_sum.begin())) - i + 1);
                //cout << search_target << ' ' << min_len << endl;
            }

        }
        if(min_len == prefix_sum.size()) return 0;
        return min_len;
    }
};
// @lc code=end

