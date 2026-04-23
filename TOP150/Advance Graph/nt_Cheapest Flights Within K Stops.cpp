class Solution {
public:
    // leetcode787
    // 下面这个方法会memory exceed的
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> ht;
        for(auto f : flights){
            ht[f[0]].push_back({f[1], f[2]});
        }
        
        queue<pair<int, int>> pq;
        vector<bool> visited(n, false);
        visited[src] = true;
        pq.push({src, 0});
        int min_cost = INT_MAX;

        // bfs，需要记录已经行走过的路径，使用bfs，当使用完所有的stop次数后
        // 返回最小的cost即可
        // 同时在bfs遍历的过程中，如果遍历到dst，就更新min_cost

        while(!pq.empty() && k >= 0){
            int size = pq.size();
            for(int i = 0; i < size; ++i){
                auto [cur_stop, cost] = pq.front(); pq.pop();
                auto next_stops = ht[cur_stop];
                for(auto ns : next_stops){
                    if(ns.first == dst){
                        min_cost = min(min_cost, cost + ns.second);
                    }
                    if(!visited[ns.first]){
                        visited[ns.first] = true;
                        pq.push({ns.first, cost + ns.second});
                    }
                    
                }
            }
            k--;
        }

        return min_cost == INT_MAX? -1 : min_cost;
    }
};

// 使用下面这个方法就好，使用的是dijkstra思想
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> ht;
        for (auto f : flights) {
            ht[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<int, int>> que;
        vector<int> distances(n, INT_MAX);

        que.push({src, 0});
        distances[src] = 0;
        
        while(!que.empty() && k >= 0) {
            k--;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto [cur, cost] = que.front(); que.pop();
                for (auto [next, next_cost] : ht[cur]) {
                    if (cost + next_cost < distances[next]) {
                        distances[next] = cost + next_cost;
                        que.push({next, cost + next_cost});
                    }
                }
            }
        }

        return distances[dst] == INT_MAX? -1 : distances[dst];
    }
};
