class Solution {
public:
    // leetcode332 重新安排行程
    // 欧拉通路，使用Hierholzer算法
    // 1. 从任意顶点出发，沿着未访问的边走，直到回到起点，形成一个环
    // 2. 如果图中还有未访问的边，选择环上任意一个顶点，重复步骤1，直到所有边都被访问
    // 3. 将所有环连接起来，形成最终的欧拉通路
    // 4. 最后将路径反转，得到正确的行程顺序
    vector<string> res;
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
