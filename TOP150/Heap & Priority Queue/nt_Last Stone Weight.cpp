class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        // tc O(nlogn), sc O(n)
        for(auto st : stones){
            pq.push(st);
        }

        while(pq.size() > 1){
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            if(s1 != s2){
                pq.push(abs(s1 - s2));
            }
        }

        return pq.size() == 0? 0 : pq.top();
    }
};
