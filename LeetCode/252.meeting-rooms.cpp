/*
 * @lc app=leetcode id=252 lang=cpp
 *
 * [252] Meeting Rooms
 */

// @lc code=start
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // 简单题，建议看看253，学习一下思想
        // map<int, int> time;
        // for(auto e : intervals){
        //     time[e[0]]++;
        //     time[e[1]]--;
        // }
        // int cnt = 0;
        // for(auto e : time){
        //     cnt += e.second;
        //     if(cnt > 1) return false;
        // }
        // return true;

        sort(intervals.begin(), intervals.end(), [](auto a, auto b){
            return a[0] < b[0];
        });

        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] < intervals[i - 1][1]) return false;
        }

        return true;

    }
};
// @lc code=end

