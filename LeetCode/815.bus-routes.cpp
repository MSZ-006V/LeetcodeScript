/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
class Solution {
public:

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // time complexity is O(n * m), n是公交车个数，m是所有车站个数
        unordered_map<int, vector<int>> stop_to_buses;
        for(int i = 0; i < routes.size(); ++i){
            for(int x : routes[i]){
                stop_to_buses[x].push_back(i); // 记录的是每一个车站，经过的公交车编号
                // 这部分很精髓，保存每个车站经过的车辆编号，也是实际中的做法
            }
        }
        // routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]]
        // 遍历完后的stop_to_buses数组中，7号车站是只有0号车经过，而15号车站经过1号车和3号车
        // 并且由于BFS的特性，访问到就是最短

        queue<int> que;
        unordered_map<int, int> dis;
        dis[source] = 0; 
        que.push(source); // 把起始车站放到队列中

        while(!que.empty()){
            int x = que.front(); que.pop();
            int dis_x = dis[x];
            for(int i : stop_to_buses[x]){ // 遍历经过当前车站x的所有公交车（编号）
                for(int y : routes[i]){ // 通过编号访问routes数组，得到公交车线路上的所有车站，遍历车站y
                    if(!dis.contains(y)){ // 如果没有访问过车站y
                        dis[y] = dis_x + 1; // 那么就记录访问到车站y的距离就是dis_x + 1
                        que.push(y); 
                    }
                }
                routes[i].clear(); // 标记 routes[i] 遍历过，因为不可能走回头路，不然就成环了，所以直接清空就行
            }
        }

        return dis.contains(target)? dis[target]:-1;
    }
};
// @lc code=end

