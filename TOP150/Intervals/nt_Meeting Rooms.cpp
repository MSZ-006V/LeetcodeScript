/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){
            if(a.start != b.start){
                return a.start < b.start;
            }
            else{
                return a.end < b.end;
            }
        });

        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i].start < intervals[i - 1].end){
                return false;
            }
        }

        return true;
    }
};

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // tc O(m), sc O(n)
        int max_range = 0;
        for(auto i : intervals){
            max_range = max(max_range, i.end);
        }
        vector<int> times(max_range + 1, 0);
        int num_r = 0;

        for(auto i : intervals){
            times[i.start]++;
            times[i.end]--;
        }
        int sum = 0;
        for(int i = 0; i < max_range + 1; ++i){
            sum += times[i];
            num_r = max(num_r, sum);
        }
        return num_r;
    }
};


// if i.end is very large, we can use map to solve this
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // tc O(NlogN), sc O(N)
        // map 会按照时间点从小到大自动排序
        // key: 时间点, value: 该时间点房间数的变化量
        map<int, int> diff;

        for (const auto& i : intervals) {
            diff[i.start]++; // 开始会议，房间需求 +1
            diff[i.end]--;   // 结束会议，房间需求 -1
        }

        int max_rooms = 0;
        int cur_rooms = 0;

        // 只遍历有会议变动的时间点
        for (auto const& [time, change] : diff) {
            cur_rooms += change;
            max_rooms = max(max_rooms, cur_rooms);
        }

        return max_rooms;
    }
};
