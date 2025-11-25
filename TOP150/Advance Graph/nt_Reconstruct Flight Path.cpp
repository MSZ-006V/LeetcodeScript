class Solution {
public:
    // leetcode332 重新安排行程
    // 欧拉通路，使用Hierholzer算法
    vector<string> res;
    // 按照字典序存储边
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> pq;

    void dfs(string ap){
        while(pq.find(ap) != pq.end() && pq[ap].size() > 0){
            string next_ap = pq[ap].top(); pq[ap].pop();
            dfs(next_ap);
        }
        res.push_back(ap);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &t : tickets){
            pq[t[0]].push(t[1]);
        }

        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
