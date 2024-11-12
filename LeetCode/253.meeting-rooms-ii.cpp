/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */

// @lc code=start
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 整体逻辑是记录每个时间点需要增加或减少几个会议室，比如实例[[0,30],[5,10],[15,20]]
        // 0 +1, 5 +1，10（结束会议）-1,15 +1，20 -1, 30 -1
        // 最后cnt肯定是0，只要记录全部会议结束后，会议室最大使用情况就可以了
        // 有点像公交车最大座位，看高峰期有多少个人
        map<int, int> tt;
        for(auto interval : intervals){
            tt[interval[0]]++;
            tt[interval[1]]--;
        }

        int cnt = 0, maxCnt = 0;
        for(auto t : tt){
            cnt += t.second;
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;
    }
};
// @lc code=end

