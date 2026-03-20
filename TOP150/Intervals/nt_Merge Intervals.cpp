class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){
            return a[0] < b[0];
        });
        int left = intervals[0][0];
        int right = intervals[0][1];
        vector<vector<int>> res;

        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] <= right){
                right = max(intervals[i][1], right);
            }
            else{
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.push_back({left, right});

        return res;
    }
};
// 似乎有一个greedy的版本，可以做到tc O(n + m), sc O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // tc O(n + m), sc O(n)
        int max_val = 0; // 记录所有区间的最大值
        for (const auto& interval : intervals) {
            max_val = max(interval[0], max_val);
        }

        // 记录每个区间的起始和能够到达的最大位置
        vector<int> mp(max_val + 1, 0);
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            mp[start] = max(end + 1, mp[start]);
        }

        vector<vector<int>> res;
        int have = -1;
        int intervalStart = -1;
        for (int i = 0; i < mp.size(); i++) {
            if (mp[i] != 0) {
                if (intervalStart == -1) intervalStart = i;
                have = max(mp[i] - 1, have);
            }
            if (have == i) { // 表示已经到达了当前区间可以到达的最大位置
                // 将当前区间加入结果中，并重置状态
                res.push_back({intervalStart, have});
                have = -1;
                intervalStart = -1;
            }
        }

        if (intervalStart != -1) {
            res.push_back({intervalStart, have});
        }

        return res;
    }
};