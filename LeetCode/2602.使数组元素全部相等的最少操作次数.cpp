/*
 * @lc app=leetcode.cn id=2602 lang=cpp
 *
 * [2602] 使数组元素全部相等的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int lower_bound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> diff(n + 1);
        for(int i = 0; i < n; ++i){
            diff[i + 1] = diff[i] + nums[i];
        }

        int m = queries.size();
        vector<long long> result;
        for(int i = 0; i < m; ++i){
            int query = queries[i];
            // ranges::lower_bound()函数的作用是在一个数组中查找大于等于指定值的第一个元素
            // ranges::upper_bound()就是查找大于指定值的第一个元素
            long long ret = ranges::lower_bound(nums, query) - nums.begin();
            long long left_area = ret * query - diff[ret]; // 小于的区间元素的值
            long long right_area = diff[n] - diff[ret] - query * (n - ret); // 大于的区间元素的值
            result.push_back(left_area + right_area); // 把两个加起来就是需要的操作数
        }
        return result;
    }
};
// @lc code=end

