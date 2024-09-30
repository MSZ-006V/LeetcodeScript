#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for(int i = 0; i < k; ++i){
        int x,y;
        cin>>x>>y;
        graph[x - 1][y - 1] = 1;
    }
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < n; ++j)
    //         cout << graph[i][j] << ' ';
    //     cout << endl;
    // }  
    
    vector<int> visited(n, 0);
    queue<int> queue;
    queue.push(0);
    visited[0] = 1;
    // BFS进行遍历，遍历到的节点打上标记
    // 最后看有没有被标记的节点就好
    while(!queue.empty()){
        int cur = queue.front();
        queue.pop();
        
        for(int i = 0; i < n; ++i){
            if(graph[cur][i] == 1 && visited[i] == 0){
                queue.push(i);
                visited[i] = 1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(visited[i] == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}