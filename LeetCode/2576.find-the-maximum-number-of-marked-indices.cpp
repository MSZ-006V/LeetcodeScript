/*
 * @lc app=leetcode id=2576 lang=cpp
 *
 * [2576] Find the Maximum Number of Marked Indices
 */

// @lc code=start
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = n / 2;

        auto check = [&](int k){
            for(int i = 0; i < k; ++i){
                if(nums[i] * 2 > nums[n - k + i]){
                    return false;
                }
            }
            return true;
        };

        int ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid)){ // 可以找到mid对匹配的，可以增大
                left = mid + 1;
                ans = mid; 
                // 这里使用ans来记录答案，因为实际上的答案是mid对，
                // 而不是left或者是right，最后是需要返回ans * 2的, 因为题目问的是多少个而不是多少对
            }
            else{
                right = mid - 1;
            }
        }
        return ans * 2; // 乘2计算出总个数然后返回
    }
};
// @lc code=end

