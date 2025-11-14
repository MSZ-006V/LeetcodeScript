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

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int x, int color){
        colors[x] = color;
        for(auto y : graph[x]){
            if( colors[y] == color || 
                (colors[y] == 0 && !dfs(graph, colors, y, -color)) // !dfs(graph, colors, y, -color) 代表如果没有染色成功，返回false，这里就会变成true，从而继续传递false
            ){
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());
        for(int i = 0; i < graph.size(); ++i){
            if(colors[i] == 0 && !dfs(graph, colors, i, 1)){
                return false;
            }
        }
        return true;
        
    }
};

