/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];

        // 使用两个数组，left和right来进行记录
        for(int i = 1; i < n; ++i){
            left[i] = left[i - 1] * nums[i];
        }

        for(int i = n - 2; i >= 0; --i){
            right[i] = right[i + 1] * nums[i];
        }

        vector<int> answer(n, 0);
        answer[0] = right[1];
        answer[n - 1] = left[n - 2];
        for(int i = 1; i < n - 1; ++i){
            answer[i] = left[i - 1] * right[i + 1];
        }
        return answer;
    }
};
// @lc code=end

