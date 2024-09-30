#include<iostream>
#include<vector>

using namespace std;

int length = 500;
vector<int> union_arr = vector<int>(length, 0);

void init(){
    for(int i = 0; i < length; ++i){
        union_arr[i] = i;
    }
}

int find(int u){
    if(union_arr[u] == u) return u;
    else return union_arr[u] = find(union_arr[u]);
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
    union_arr[v] = u;
}
int main(){
    // 这一题是并查集查找的基础操作，非常简单
    // 接收数据，然后使用join()，最后查找source和destination是否在同一个集合就可以
    init();
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i = 0; i < m; ++i){
        cin>>u>>v;
        join(u, v);
    }
    cin>>u>>v;
    // for(int i = 0; i < n; ++i){
    //     cout << union_arr[i] << endl;
    // }
    if(isSame(u, v))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}