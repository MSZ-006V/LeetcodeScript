/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // time complexity is O(nlogn), space complexity is O(n)
        unordered_set<int> set; // 利用哈希表来记录出现过的数
        sort(nums.begin(), nums.end()); // 递增排序
        int count = 0;
        // 因为nums[0]是最小的，不能再出现了
        // 所以下一个可以出现的数一定就是nums[0] + 1, min记录就是可以出现的数
        int min = nums[0] + 1; 
        set.insert(nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            if(set.contains(nums[i])){
                count = count + (min - nums[i]);
                nums[i] = min;
            }
            min = nums[i] + 1; // 每一次遍历都要保证下一个可以出现的数是多少，因为数组是递增排序的
            set.insert(nums[i]); // 记录数
        }
        
        return count;
    }
};
// @lc code=end

