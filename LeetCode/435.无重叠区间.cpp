/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int delete_num = 0;
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] < intervals[i - 1][1]){ // 有这种情况，就是重叠了，所以删除个数+1
                delete_num++;
                intervals[i][1] = intervals[i - 1][1]; // 把前一个的小范围复制到后面大范围的，使后一个大范围的减小，便于后面进行判断
            }
        }
        return delete_num;
    }
};
// @lc code=end

