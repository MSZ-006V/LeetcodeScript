/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
struct edge{
    int l, r, val;
};
class unionfind{
public:
    vector<int> father;
    unionfind(int n){
        father = vector<int>(n, 0);
        for(int i = 0; i < n; ++i){
            father[i] = i;
        }
    }
    bool isSame(int u, int v){
        u = find(u);
        v = find(v);
        return u == v;
    }
    int find(int u){
        if(u == father[u]) return u;
        else return father[u] = find(father[u]); // 注意这里的写法
        // 是father[u] = , 而不是 ==，用来做路径压缩的
    }
    void join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        father[v] = u;
    }
};

class Solution {
public:
    int kruskal(unionfind& uf, vector<edge>& edges, int edge_num, int vertex_num){
        int n = vertex_num - 1;
        int cost = 0;
        vector<edge> tree;
        for(int i = 0; i < edge_num; ++i){
            if(!uf.isSame(edges[i].l, edges[i].r)){
                uf.join(edges[i].l, edges[i].r);
                cost += edges[i].val;
                tree.push_back(edges[i]);
                n -= 1;
                if(n == 0) break;
            }
        }
        return cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 计算manhattan距离
        auto manhattan_dis = [&](auto a, auto b){
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };
        int n = points.size();
        unionfind uf(n);
        vector<edge> edges; // 使用自定义edge数据结构建立数组
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){ // j = i + 1, 不需要重复计算
                edges.push_back({i, j, manhattan_dis(points[i], points[j])});
            }
        }
        sort(edges.begin(), edges.end(), [](auto& a, auto& b){
            return a.val < b.val;
        }); // 排序
        
        int cost = kruskal(uf, edges, edges.size(), n);

        return cost;
    }
};
// @lc code=end

