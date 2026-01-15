/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // time complexity is O(n), space complexity is O(1)
        // if(nums.size() == 1) return 0;
        // int n = nums.size(); 
        // if(nums[0] > nums[1]) return 0;
        // if(nums[n - 1] > nums[n - 2]) return n - 1;

        // for(int i = 1; i < n - 1; ++i){
        //     if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
        //         return i;
        //     }
        // }
        // return 0;

        // 这道题也可以使用二分方法，需要一个定理
        // 即：如果i < n - 1, 并且nums[i] < nums[i + 1]，那么在下标[i + 1, n - 1]中一定有一个峰值
        // 可以使用反证法证明，这一道题二分的闭区间范围是[0, n - 2]
        // 实例[1, 2, 3, 1], return index = 2

        // 可以设想，这个数组的前半段一定是有一段是递增的，那么只需要找到递增的尾部就可以

        int n = nums.size();
        int left = 0, right = n - 2;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid + 1]){ // 必须是严格的大于
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }
};
// @lc code=end

