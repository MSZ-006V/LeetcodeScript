/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n, 0);
        // 存储的是<会议室编号>
        priority_queue<int, vector<int>, greater<>> idle;
        for(int i = 0; i < n; ++i) idle.push(i);

        // 存储的是<会议室结束时间, 会议室编号>，按照会议结束时间进行排序
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> using_;
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });

        for(auto& m : meetings){
            // 遍历每一场会议，都会保证这场会议一定能够举办
            long sarttime = m[0], end = m[1], id;
            // 会议室使用队列中不为空，并且开头的会议室结束时间小于等于当前的时间, 说明当前在队列头的这个会议室该结束了
            while(!using_.empty() && using_.top().first <= sarttime){
                idle.push(using_.top().second); // 把结束会议的会议室编号放入idle里面
                using_.pop(); // 弹出
            }

            // 总之下面的if语句一定能够找到一个可用的会议室给当前这场会议
            if(idle.empty()){ // 针对时间偏移的情况
                auto [e, i] = using_.top(); using_.pop(); // 没有可用的会议室，那么弹出一个最早结束的会议室（若有多个同时结束的，会弹出下标最小的）
                end += e - sarttime; // 此时当前会议开始时间大于目前最早结束会议室的结束时间，所以要推迟开始时间
                id = i;
            }
            else{ // 如果有可用的会议室的情况
                id = idle.top(); // 直接弹出一个空闲的会议室的id号
                idle.pop();
            }
            rooms[id]++; // 然后直接使用当前会议室
            using_.push(std::make_pair(end, id));
        }

        int ans_id = 0;
        for(int i = 0; i < n; ++i){
            if(rooms[i] > rooms[ans_id]){
                ans_id = i;
            }
        }
        return ans_id;
    }
};
// @lc code=end

