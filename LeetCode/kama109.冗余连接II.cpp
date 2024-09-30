#include<iostream>
#include<vector>

using namespace std;

int length = 1000;
vector<int> set = vector<int>(length, 0);

void init(){
    for(int i = 0; i < length; ++i){
        set[i] = i;
    }
}

int find(int u){
    if(set[u] == u){
        return u;
    }
    else{
        return set[u] = find(set[u]);
    }
}

bool isSame(int u, int v){
    u = find(u);
    v = find(v);
    return u == v;
}

void join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
        return ;
    }
    set[v] = u;
}

bool remove_2_edge(vector<vector<int>>& edges, int delete_edge){
    init();
    for(int i = 0; i < edges.size(); ++i){
        if(i == delete_edge) // 遇到要删除的边，跳过
            continue;
        // 如果删除了指定的边（最后一条边），仍然还有环形成
        // 说明就是删错边了，删最后一条边没用
        // 返回false，删第二条边
        if(isSame(edges[i][0], edges[i][1])){ 
            return false;
        }
        join(edges[i][0], edges[i][1]);
    }
    // 成功走出循环说明删对了，删除最后一条边就可以组成一个有向树，返回true
    return true;
}

void remove_ring_edge(vector<vector<int>>& edges){
    init();
    for(int i = 0; i < edges.size(); ++i){
        if(isSame(edges[i][0], edges[i][1])){ // 如果加入新的边，这条边的两个端点都已经在集合里面了，说明就构成了一个环，所以这个边删掉就好了
            cout << edges[i][0] << ' ' << edges[i][1] << endl;
            return;
        }
        join(edges[i][0], edges[i][1]);
    }
}

int main(){
    int n, u, v;
    cin>>n;
    vector<vector<int>> edges;
    vector<int> rank(n + 1, 0);
    // 将所有的边存入edges数组中
    for(int i = 0; i < n; ++i){
        cin>>u>>v;
        rank[v]++; // 统计每一条边的入度，即有多少条边指向那个顶点
        edges.push_back({u, v});
    }
    
    vector<int> rank2; // 记录入度为2的边
    // 倒着放入边，因为题目要求如果删2条边都可以，就删最后一条
    // 倒着放入可以将最后一条边放到最前面，在下面就是rank[0]
    for(int i = n - 1; i >= 0; --i){ 
        if(rank[edges[i][1]] >= 2){
            rank2.push_back(i);
        }
    }
    // vec的长度要么是1，要么是2，或者是0
    
    // 情况1，情况2，分别是存在入度为2的边，删除靠后的一条边
    // 还有一个是存在入度为2的一个节点，但是只能删除一条特定的边
    // 这两种情况下，vec的长度要么是1要么是2
    if(rank2.size() > 0){
        if(remove_2_edge(edges, rank2[0])){
            cout << edges[rank2[0]][0] << ' ' << edges[rank2[0]][1] << endl;
            return 0;
        }
        else{
            // 代表返回了false，那就代表rank2数组长度一定是2
            // 删除最后一条边是错的，那么就一定就是删除倒数第二条边
            cout << edges[rank2[1]][0] << ' ' << edges[rank2[1]][1] << endl;
            return 0;
        }
    }
    
    // 情况3，此时不存在入度为2的边，但是构成一个环
    // 只要找到最后使得变成环的那条边，然后删除就可以了
    remove_ring_edge(edges);
    return 0;
}