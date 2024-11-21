/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // time complexity O(n), space complexity O(1)
        // 和209是同样的一个思路
        if(k <= 1) return 0;
        int ans = 0;
        int prod = 1;
        int left = 0;
        for(int right = 0; right < nums.size(); ++right){
            prod = prod * nums[right];
            while(prod >= k){ // 如果不满足条件了，就收缩左边区间直到满足条件，所以while循环结束的时候一定是满足条件的区间
                prod = prod / nums[left];
                left++;
            }
            ans += right - left + 1; // 此时[left, right]这个区间都是满足条件的
            // 而这个区间的子数组个数从[left, right], [left + 1, right], ..., [right, right], 一共是right - left + 1个，所以直接加上就可以了
        }

        return ans;
    }
};
// @lc code=end

