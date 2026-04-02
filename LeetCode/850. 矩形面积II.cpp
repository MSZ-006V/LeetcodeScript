struct Event {
    int x, type, y1, y2;
    bool operator<(const Event& other) const {
        return x < other.x;
    }
};

class Solution {
public:
    // 计算一维线段并集的长度
    // 计算y轴上的被矩形覆盖的面积，比如针对[2, 10], [5, 15], [20, 25]
    // 那么遍历到[5, 15], 只是扩展边界，不计算
    // 遍历到[20, 25], 之前的边界是[2, 15], 那么就计算，然后刷新边界
    long long calculateYLength(vector<pair<int, int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        long long total = 0;
        int curL = intervals[0].first, curR = intervals[0].second;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].first < curR) {
                curR = max(curR, intervals[i].second);
            } else {
                total += (curR - curL);
                curL = intervals[i].first;
                curR = intervals[i].second;
            }
        }
        return total + (curR - curL); // 计算最后一个
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<Event> es;
        for (auto& r : rectangles) {
            es.push_back({r[0], 1, r[1], r[3]});  // 入边
            es.push_back({r[2], -1, r[1], r[3]}); // 出边
        }
        sort(es.begin(), es.end());
        for(auto e : es){
            cout << e.x << ' ' << e.type << ' ' << e.y1 << ' ' << e.y2 << endl;
         }

        long long res = 0;
        long long mod = 1e9 + 7;
        vector<pair<int, int>> active_y; // 存储当前扫描线横跨的所有 [y1, y2] 区间
        int pre_x = es[0].x;

        for (auto& e : es) {
            // 1. 先结算：计算从上一个 x 到现在这个 x 之间的面积
            int width = e.x - pre_x;
            if (width > 0) {
                res = (res + (long long)width * calculateYLength(active_y)) % mod;
            }

            // 2. 更新状态：添加或删除 Y 轴区间
            if (e.type == 1) {
                active_y.push_back({e.y1, e.y2});
            } else { // 遍历active_y，查找对应的对象，精准删除
                for (auto it = active_y.begin(); it != active_y.end(); ++it) {
                    if (it->first == e.y1 && it->second == e.y2) {
                        active_y.erase(it);
                        break;
                    }
                }
            }
            pre_x = e.x;
        }
        return res;
    }
};