// bellman_ford算法专门针对带负权值的有向图的最短路径问题
// 相比于dijkstra算法，bf算法可以处理负权值，循环需要进行n-1次
// 对每一条边进行n-1次“松弛”操作
// 松弛操作即：
// if(min_dist[v1] != INT_MAX && min_dist[v2] > min_dist[v1] + val){
//     min_dist[v2] = min_dist[v1] + val;
#include<iostream>
#include<climits>
#include<vector>

using namespace std;

void bellman_ford(vector<vector<int>>& edges, int n){
    vector<int> min_dist(n + 1, INT_MAX);
    min_dist[1] = 0;
    int v1,v2,val;
    for(int i = 1; i < n; ++i){
        for(vector<int>& edge:edges){
            v1 = edge[0];
            v2 = edge[1];
            val = edge[2];
            if(min_dist[v1] != INT_MAX && min_dist[v2] > min_dist[v1] + val){
                min_dist[v2] = min_dist[v1] + val;
            }
        }
    }
    if(min_dist[n] == INT_MAX){
        cout << "unconnected" << endl;
    }
    else{
        cout << min_dist[n] << endl;
    }
}

int main(){
    int n,m,v1,v2,val;
    cin>>n>>m;
    vector<vector<int>> graph;
    for(int i = 0; i < m; ++i){
        cin>>v1>>v2>>val;
        graph.push_back({v1, v2, val});
    }  
    bellman_ford(graph, n);
}