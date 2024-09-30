/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int lower_bound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){ // 闭区间[left, right]
            int mid = left + (right - left)/2;
            if(nums[mid] < target){ // 注意，这里如果是小于的情况，就写left变化
                left = mid + 1;
            }
            else{
                right = mid - 1; // right的情况就是>=target
            }
        }
        return left; // 最后返回left
        // 可以考虑下面这种情况，目标为2，数组为2,2,2,2，查找的理想结果应该是
        // left=0，right=-1，这样left就是数组的起始位置，所以上面left变动的情况必须是 < target
        // 而right变动是 >= target,这样查找的结果就是left=0,right=-1,返回的left就正好是区间的开头
        // 如果是left变动是 <= target, 对于上面这种数组的查找结果就是left=4,right=3,返回的left
        // 就不是区间的开头了
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target); // 此时返回的结果就是区间的开头
        if(start == nums.size() || nums[start] != target) return {-1, -1};
        // 可以用2个不同实例，比如[1,1,1,1], target=2, 返回start是left=4，所以start=nums.size(),在整个数组中都找不到target这个数
        // 而对于[2,2,2,2], target=1, 返回的start是left=0，满足nums[start]!=target,代表数组中所有的数都大于target，找不到
        int end = lower_bound(nums, target + 1) - 1; // 因为是有序数组，所以查找target+1的话，就会找到target的区间范围结果的下一个数，这个数一定是大于target的
        // 所以返回后再减去1，就是target范围的结果了，即使target+1这个数不在数组中，也不会影响
        return {start, end};
    }
    // 参考灵神视频https://www.bilibili.com/video/BV1AP41137w7/?vd_source=fa7cb1619d366c22c8a7cd1323bc6cef
};
// @lc code=end

