// leetcode 1584. Min Cost to Connect All Points
vector<int> unionset;
void init(int n){
    unionset.assign(n, 0);
    for(int i = 0; i < n; ++i){
        unionset[i] = i;
    }
} 

int find(int u){
    if(u == unionset[u]) return u;
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

struct edge{
    int l, r, val;
};

class Solution {
public:
    int kruskal(int n, vector<edge>& edges){
        int v = n - 1;
        int cost = 0;

        for(int i = 0; i < edges.size(); ++i){
            if(!isSame(edges[i].l, edges[i].r)){
                join(edges[i].l, edges[i].r);
                cost += edges[i].val;
                
                v -= 1;
                if(v == 0) break;
            }
        }
        return cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // kruskal最小生成树算法（找到这个图的最小生成树
        // 最小生成树：包括图中所有的顶点，并且权值最小
        int n = points.size();
        init(n);
        auto dis = [](auto a, auto b){
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };

        vector<edge> edges;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                edges.push_back({i, j, dis(points[i], points[j])});
            }
        }
        sort(edges.begin(), edges.end(), [](auto a, auto b){
            return a.val < b.val;
        }); // 从小到大排序

        return kruskal(n, edges);
    }
};
