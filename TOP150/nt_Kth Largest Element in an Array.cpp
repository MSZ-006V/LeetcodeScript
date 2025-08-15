class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // tc O(n * logn), sc O(n)
        priority_queue<int> pq;
        for(auto num : nums){
            pq.push(num);
        }

        while(k-- > 1){
            pq.pop();
        }

        return pq.top();
    }
};
