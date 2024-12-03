/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // time complexity is O(n * m), space complexity is O(n * m)
        // 运用BFS，限制查找的次数，即时停止循环
        // 最开始写的不对是因为对某些例子会错误，最开始写是一直更新cost中的最小值
        // 写一个cost[] = min(cost[], cost[] + val), 这样子是不对的，会导致后续需要的数据被更小的覆盖
        // 但是更小代价的那条路并不能走到终点，就导致了错误
        // 后续改成queue<pair<int, int>> que，每次把新的节点插入的时候，就顺带把当前的cost也插入队列了
        // 这样子就保证了不会被更小代价（但是走不到终点）的路覆盖，所以就正确了

        // 最开始错误例子：[[0,1,1],[0,2,5],[1,2,1],[2,3,1]], n = 4, src = 0, dst = 3, k = 1, result = 6
        unordered_map<int, vector<pair<int, int>>> edges;
        // first one is start, second one end, third one is cost
        for(auto f : flights){
            edges[f[0]].push_back(make_pair(f[1], f[2]));
        }

        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        queue<pair<int, int>> que;
        que.push(make_pair(src, 0));

        while(!que.empty() && k >= 0){
            k--;
            int size = que.size();
            for(int i = 0; i < size; ++i){
                auto cur = que.front(); que.pop();
                for(auto& d : edges[cur.first]){
                    int val = cur.second + d.second;
                    if(val < cost[d.first]){
                        que.push(make_pair(d.first, val));
                        cost[d.first] = val;
                    }
                }
            }
        }

        return cost[dst] == INT_MAX?-1:cost[dst];
    }
};
// @lc code=end

