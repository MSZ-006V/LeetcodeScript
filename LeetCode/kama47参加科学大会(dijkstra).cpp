// 这道题也有使用堆进行优化的版本（即小顶堆，使用优先队列进行实现）

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void dijkstra(vector<vector<int>>& graph, int n){
    vector<int> min_dist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    min_dist[1] = 0;
    
    for(int i = 1; i < n + 1; ++i){
        int cur = 1;
        int min_distance = INT_MAX;
        for(int j = 1; j < n + 1; ++j){
            if(visited[j] != true && min_dist[j] < min_distance){
                cur = j;
                min_distance = min_dist[j];
            }
        }
        visited[cur] = true;
        for(int j = 1; j < n + 1; ++j){
            if(graph[cur][j] != 0 && visited[j] == false && min_dist[cur] + graph[cur][j] < min_dist[j]){
                min_dist[j] = min_dist[cur] + graph[cur][j];
            }
        }
    }
    
    // for(int i = 1; i < n + 1; ++i){
    //     cout << min_dist[i] << ' ';
    // }
    if(min_dist[n] == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << min_dist[n] << endl;
    }
    
}

int main(){
    int n,m,v1,v2,val;
    cin>>n>>m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m; ++i){
        cin>>v1>>v2>>val;
        graph[v1][v2] = val;
    }
    dijkstra(graph, n);
}