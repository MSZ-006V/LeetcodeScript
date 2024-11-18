/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
private:
    vector<int> father;
    
    void init(int n){
        father.resize(n);
        for(int i = 0; i < n; ++i){
            father[i] = i;
        }
    }

    int find(int u){
        if(u == father[u]) return u;
        else return father[u] = find(father[u]);
    }

    bool isSame(int u, int v){
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return ;
        father[v] = u;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // 并查集，使用偏移量进行分组
        int n = graph.size();
        init(2 * n);
        for(int i = 0; i < graph.size(); ++i){
            vector<int>& points = graph[i];
            for(auto v : points){
                if(isSame(i, v)) return false; // 如果找到，则返回false
                join(i + n, v); // 偏移量进行分组
                join(i, v + n); // 偏移量进行分组
            }
        }

        return true;
    }
};
// @lc code=end

