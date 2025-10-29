class Solution {
public:
    // tc O(nlogn + mlogm), sc O(n + m)
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // 区间排序，按照start从小到大进行排序
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0] < b[0]; 
        });

        vector<int> sortedQuery = queries;
        sort(sortedQuery.begin(), sortedQuery.end()); // 将query从小到大排序
        map<int, int> res;

        // 比较器，从大到小排序，如果第一个相同那就比较第二个
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        // pq内记录元素为[区间长度，区间右端点]
        // 堆顶是当前所有可选区间中长度最小的那个
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        int i = 0;
        for(auto q : sortedQuery){
            // 首先对一个元素，把包含这个元素的区间都放入pq中
            // 维护一个最小堆pq,里面存当前“可能覆盖当前 query”的所有区间
            while(i < intervals.size() && intervals[i][0] <= q){
                int l = intervals[i][0];
                int r = intervals[i][1];
                // 把所有左端点 ≤ query的区间加入堆
                pq.push({r - l + 1, r});
                i++;
            }
            
            // 把右端点 < query的区间从堆里弹出（因为这些区间已经不覆盖当前query了）
            while(!pq.empty() && pq.top()[1] < q){
                pq.pop();
            }

            // 上面这两步也有区别，先用左端点来检查，因为必须左端点 <= q，才能压入，但是压入的时候记录的是右端点
            // 所以下一步用右端点来比较，如果 右端点 < q，那么就证明这个区间不包含q，所以要弹出

            // 如果弹出后，pq为空，那么代表没有任何一个区间包含这个query，那么结果就是-1
            // 如果不为空，那么就直接取出pq顶部元素记录，pq顶部元素就是interval长度最短，并且包含该query的
            res[q] = pq.empty()? -1 : pq.top()[0];
        }

        vector<int> result(queries.size());
        for(int j = 0; j < queries.size(); ++j){
            result[j] = res[queries[j]];
        }

        return result;
    }
};
