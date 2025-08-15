class KthLargest {
public:
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int limit;
    KthLargest(int k, vector<int>& nums) {
        // tc O(n * log k), sc O(k)
        // 优先队列调整一次耗时是logk
        limit = k;
        for(auto num : nums){
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        // tc O(log k)
        pq.push(val);
        if(pq.size() > limit){
            pq.pop();
        }

        return pq.top();
    }
};
