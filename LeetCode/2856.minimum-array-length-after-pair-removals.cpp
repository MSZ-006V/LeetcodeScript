/*
 * @lc app=leetcode id=2856 lang=cpp
 *
 * [2856] Minimum Array Length After Pair Removals
 */

// @lc code=start
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        // 可以看视频https://www.bilibili.com/video/BV1PV411N76R/?vd_source=fa7cb1619d366c22c8a7cd1323bc6cef
        // 对于数组长度n，分类进行讨论，设数组中出现次数最多的元素出现次数为CX
        // 如果CX > n/2，那么出现次数最多的数字和其他数字相互抵消后，一定还剩下2*CX-n
        // 如果CX <= n/2，那么可以证明（证明看视频或题解），最后全部都可以消掉，只剩下0或1（取决于数组长度奇偶）
        int n = nums.size();
        int x = nums[n / 2]; // 假设CX > n/2，下面一行代码求出CX的数量
        // 下面这种方式实际上就是找出某个数的区间范围也就是个数，标准的lc34题写法
        int max_cnt = ranges::upper_bound(nums.begin(), nums.end(), x) - ranges::lower_bound(nums.begin(), nums.end(), x);
        return max(max_cnt * 2 - n, n % 2); // 分类讨论，取最大的
        // 因为max_cnt * 2 - n 可能是负数的，第二项只能是0或1，永远不变
        // 如果第一项比第二项大，那肯定取第一项，如果第一项<=0，那肯定就取第二项
    }
};
// @lc code=end

