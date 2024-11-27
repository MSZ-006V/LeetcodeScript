/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    // 和55题跳跃游戏不同
    int jump(vector<int>& nums) {
        int ans = 0;
        int cur_right = 0;
        int next_right = 0;
        // 只需要遍历到n − 2，因为完整的解释是，如果遍历到最后一个数(n - 1), 那就是要找从最后一个数
        // 到下一步能走的最大距离了，不符合题意了，所以i不用遍历到最后一个
        // 同时，尽管只遍历到n-2, 但是这个时候在n-2是一定可以到达最后一个位置的，因为题目中保证生成的测试用例可以到达 nums[n - 1]
        // 所以能走到n-2就已经能够走到n-1，求走到n-2的步数就可以了
        for(int i = 0; i < nums.size() - 1; ++i){
            next_right = max(next_right, nums[i] + i);
            if(i == cur_right){
                cur_right = next_right;
                ans++;
            }
        }

        return ans;
    }
};
// @lc code=end

