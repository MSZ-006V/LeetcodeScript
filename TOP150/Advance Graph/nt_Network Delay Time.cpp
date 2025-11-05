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
