class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 实际上是 Dijkstra 算法
        vector<vector<pair<int,int>>> graph(n + 1);
        for (auto &t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        vector<bool> visited(n + 1, false);

        // {distance, node}
        // 默认的std::priority_queue是最大堆（max-heap），队列最开始的元素是最大的
        // C++ STL 默认提供了 std::greater 和 std::less 这两个函数对象：
        // std::less<T> 让堆变成最大堆（默认情况）
        // std::greater<T> 让堆变成最小堆
        // 同时pair<int, int>具有默认的比较规则，即first先比较，如果相等再比较second
        // 所以下面这种声明方式，意思是创建一个最小堆，同时默认按照pair的first元素进行比较，队列头部是pair中first最小的元素
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (visited[u]) continue;
            visited[u] = true;

            for (auto &[v, w] : graph[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};

// 简化版本
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto &t : times){
            graph[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        auto cmp = [](auto a, auto b){
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({k, 0}); // node, weight

        while(!pq.empty()){
            auto [u, d] = pq.top(); pq.pop();
            
            // 在通常的堆实现里我们没有直接支持「减小键值（decrease-key）」操作，所以当我们发现更短的到达某个节点的路径时，会再次把这个节点和新的更小距离入堆，而旧的（更大的）距离条目仍然留在堆里 —— 这就会产生 stale（过期）条目。
            // if (d > dist[u]) continue; 的作用就是跳过这些过期条目，避免重复/无意义的松弛操作，从而保证效率（并防止在错误的实现中影响正确性）。
            if(d > dist[u]) continue;

            for(auto &[v, weight] : graph[u]){
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                    pq.push({v, dist[v]});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};


