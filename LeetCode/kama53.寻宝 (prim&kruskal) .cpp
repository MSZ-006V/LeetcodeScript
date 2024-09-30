#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int length = 10001;
vector<int> father = vector<int>(length, 0);

struct edge{
    int l, r, val;
};

void init(){
    for(int i = 0; i < length; ++i){
        father[i] = i;
    }
}

int find(int u){
    if(father[u] == u)
        return u;
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
    if(u == v)
        return;
    father[v] = u;
}

void kruskal(vector<edge>& edges, int edge_num, int v){
    int n = v - 1;
    vector<edge> tree;
    for(int i = 0; i < edge_num; ++i){
        if(!isSame(edges[i].l, edges[i].r)){
            join(edges[i].l, edges[i].r);
            tree.push_back(edges[i]);
            n -= 1;
            if(n == 0) break;
        }
    }
    
    // for(int i = 0; i < tree.size(); ++i){
    //     cout << tree[i].l << tree[i].r << tree[i].val << endl;
    // }
    int result = 0;
    for(int i = 0; i < tree.size(); ++i){
        result += tree[i].val;
    }
    cout << result << endl;
}

int main(){
    init();
    int v,e;
    cin>>v>>e;
    int v1,v2,value;
    vector<edge> edges;
    for(int i = 0; i < e; ++i){
        cin>>v1>>v2>>value;
        edges.push_back({v1, v2, value});
    }
    
    sort(edges.begin(), edges.end(), [](const edge& a, const edge& b){
        return a.val < b.val;
    });
    
    kruskal(edges, e, v);
    
    
    
}