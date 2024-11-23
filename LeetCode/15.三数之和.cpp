/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 相比于四数之和，少一重循环
        // 用一个循环i，来固定一个数i，然后移动left和right来找
        vector<vector<int>> result;
        // 先对数组进行增序排序，从小到大
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0){ 
            // 如果第一个数就大于0的话，后面的所有树都是大于0的，
            // 不可能三个数加起来等于0了，后面也不可能找到了，直接返回结果就可以
                return result;
            }

            if(i > 0 && nums[i] == nums[i - 1]){ // 如果0,1,1这种情况，第二个1就不会计算了
                continue;
            }
            // 固定最左边的树，在后面的区间寻找
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                // 如果大了，就减小rig，让和变小
                // 如果小了，就增大left，让和变大
                if(nums[i] + nums[left] + nums[right] > 0) right--;
                else if(nums[i] + nums[left] + nums[right] < 0) left++;
                else{
                    // 如果找到一个结果，就同时增减left和right，寻找可能得下一个结果
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left < right && nums[right] == nums[right - 1]) right--; // 去重
                    while(left < right && nums[left] == nums[left + 1]) left++; // 去重
                    
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

