/*
 * @lc app=leetcode.cn id=1685 lang=cpp
 *
 * [1685] 有序数组中差绝对值之和
 */

// @lc code=start
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // 实际思路，和2602是完全一样的，找到nums[i]的后一个数，然后计算左右的面积并相加即可
        
        int n = nums.size();
        vector<int> diff(n + 1);
        for(int i = 0; i < n; ++i){
            diff[i + 1] = diff[i] + nums[i];
        }

        vector<int> result;
        for(int i = 0; i < n; ++i){
            int index = ranges::lower_bound(nums, nums[i]) - nums.begin();
            // cout << index << endl;
            int left = nums[i] * index - diff[index];
            int right = diff[n] - diff[index] - nums[i] * (n - index);
            result.push_back(left + right);
        }
        return result;
    }
};
// @lc code=end

