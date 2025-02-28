/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int res = 0;

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        // dp[i][j] 代表的是：
        // nums1[0:i]（即 nums1 前 i 个元素）
        // 和 nums2[0:j]（即 nums2 前 j 个元素） 
        // 结尾的公共子数组（必须是连续的）的最大长度
        // 因为有一个res不停地记录最大长度，所以其实不用考虑到具体是哪一段最大
        
        for(int i = 1; i < l1 + 1; ++i){
            for(int j = 1; j < l2 + 1; ++j){
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if(dp[i][j] > res){
                    res = dp[i][j];
                }
            }
        }

        return res;
    }
};
// @lc code=end

