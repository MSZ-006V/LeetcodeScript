class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& es, vector<bool>& visited, int node){
        visited[node] = true;
        for(int nei : es[node]){
            if(!visited[nei]){
                dfs(es, visited, nei);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // 计算最大连通分量
        // 对于无向图，连通分量的定义可以表述为：
        // 一个连通分量包含一组节点，这些节点之间通过无向边直接或间接相连。
        // 图中每个节点都属于一个且仅属于一个连通分量。
        // 简单来说，无向图的连通分量是图中被边连起来的独立部分。
        unordered_map<int, vector<int>> es;
        vector<bool> visited(n, false);

        for(auto e : edges){
            es[e[0]].push_back(e[1]);
            es[e[1]].push_back(e[0]);
        }

        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                dfs(es, visited, i);    
                cnt++;
            }
        }

        return cnt;
    }
};
