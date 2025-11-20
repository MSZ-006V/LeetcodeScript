class Solution {
public:
    int n = 101;
    vector<int> union_set;
    
    void init(){
        union_set = vector<int>(n, 0);
        for(int i = 0; i < n; ++i){
            union_set[i] = i;
        }
    }

    int find(int u){
        if(union_set[u] == u)
            return u;
        else return union_set[u] = find(union_set[u]);
    }

    bool isSame(int u, int v){
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        union_set[v] = u;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 只是最简单的冗余连接类型，用并查集就可以解决
        // 详情见leetcode684,685
        init();
        for(int i = 0; i < edges.size(); ++i){
            vector<int> edge = edges[i];
            if(isSame(edge[0], edge[1])){
                return edges[i];
            }
            else{
                join(edge[0], edge[1]);
            }
        }
        return {};
    }
};

// 更简洁的版本

class Solution {
    vector<int> unionset;
    void init(){
        unionset = vector<int>(101, 0);
        for(int i = 0; i < 101; ++i){
            unionset[i] = i;
        }
    }
    
    int find(int u){
        if(unionset[u] == u) return u;
        else return unionset[u] = find(unionset[u]);
    }

    bool isSame(int u, int v){
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        unionset[v] = u;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();

        for(auto e : edges){
            if(!isSame(e[0], e[1])){
                join(e[0], e[1]);
            }
            else{
                return e;
            }
        }

    }
};
