class Solution {
    bool isRing;
public:
    void dfs(vector<bool>& visited, unordered_map<int, vector<int>>& edges, int node, int parent){
        // 两种方法都对，下面那种方法看着更符合直觉一点，其实就是无向图判断有没有环
        // 可以使用并查集或者是DFS/BFS

        // visited[node] = true;

        // for (auto neighbor : edges[node]) {
        //     if (!visited[neighbor]) {
        //         dfs(visited, edges, neighbor, node);
        //     } else if (neighbor != parent) {  
        //         isRing = true;
        //     }
        // }

        if(visited[node]){
            isRing = true;
            return;
        }
        visited[node] = true;

        for(auto e : edges[node]){
            if(e == parent) continue;
            dfs(visited, edges, e, node);
        }

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        isRing = false;
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> es;
        
        for(auto e : edges){
            es[e[0]].push_back(e[1]);
            es[e[1]].push_back(e[0]);
        }

        dfs(visited, es, 0, -1);
        if(isRing) return false;

        for (bool v : visited) {
            if (!v) return false;
        }
    }
};
