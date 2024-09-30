/*
 * @lc app=leetcode.cn id=3152 lang=cpp
 *
 * [3152] 特殊数组 II
 */

// @lc code=start
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> dp(nums.size(), 1);
        // 这里使用一个位运算来判断相邻数的奇偶性
        for(int i = 1; i < nums.size(); ++i){
            if((nums[i] ^ nums[i - 1]) & 1){
                dp[i] = dp[i - 1] + 1;
                // 如果相邻数奇偶性不同，那么第i位元素就可以加入到前面dp[i - 1]所代表的序列里面
            }
        }

        vector<bool> result;
        for(auto query : queries){
            if(dp[query[1]] >= query[1] - query[0] + 1){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }

        return result;
    }
};
// @lc code=end

