/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        int left = intervals[0][0], right = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] <= right){
                if(right < intervals[i][1]){
                    right = intervals[i][1];
                }
            }
            else{
                result.push_back({left, right});
                left = intervals[i][0], right = intervals[i][1];
            }
        }
        result.push_back({left, right});
        return result;
    }
};
// @lc code=end

