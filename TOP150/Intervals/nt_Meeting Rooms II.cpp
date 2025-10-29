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
        // 按照每个会议的开始时间，从小到大进行排序
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){
            return a.start < b.start;
        });

        // 最小堆，元素小的会在堆顶
        // 堆顶是“最早结束的会议”的结束时间
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for(auto i : intervals){
            // 每次检查一个interval，因为会议已经按照开始时间进行排序，如果当前会议的开始时间小于堆顶的元素
            // 那么说明当前会议可以**复用**堆顶的会议使用的会议室中，否则就需要新开一个会议室
            if(!pq.empty() && pq.top() <= i.start){
                pq.pop();
            }
            pq.push(i.end);
        }

        return pq.size();
    }
};
