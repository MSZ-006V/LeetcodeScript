/*
 * @lc app=leetcode id=2187 lang=cpp
 *
 * [2187] Minimum Time to Complete Trips
 */

// @lc code=start
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // 一个思路，很简单，就是在一个时间区间里面不停地寻找就可以
        long long left = 1;
        long long right = (long long)*min_element(time.begin(), time.end()) * (long long)totalTrips;
        long long ans = 1;
        while(left <= right){ // 遍历的是需要的时间
            long long mid = left + (right - left) / 2;
            long long trips = 0;
            for(auto t : time){
                trips += mid / t;
            }
            if(trips >= totalTrips){ // 在当前时间，能完成的班数大于要求的，时间还可以更短
                right = mid - 1;
            }
            else{
                left = mid + 1;
                ans = left;
            }
        }
        return left;
    }
};
// @lc code=end

