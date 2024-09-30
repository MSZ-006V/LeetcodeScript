#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
// 拓扑排序，见数据结构笔记的图论部分
void topology_sort(unordered_map<int,vector<int>>& edges, vector<int>& input_rank, int n){
    vector<int> result;
    queue<int> que;
    for(int i = 0; i < n; ++i){
        if(input_rank[i] == 0)
            que.push(i);
    }
    
    while(que.size() != 0){
        int cur = que.front();
        que.pop();
        result.push_back(cur);
        
        vector<int> cur_edges = edges[cur];
        if(cur_edges.size()){
            for(int i = 0; i < cur_edges.size(); ++i){
                input_rank[cur_edges[i]]--;
                if(input_rank[cur_edges[i]] == 0){
                    que.push(cur_edges[i]);
                }
            }
        }
    }
    if(result.size() != n){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < n - 1; ++i){
        cout << result[i] << ' ';
    }
    cout << result[n - 1] << endl;
}
int main(){
    int n,m, v1, v2;
    cin>>n>>m;
    
    vector<int> input_rank(n, 0);
    unordered_map<int,vector<int>> edges;
    
    for(int i = 0; i < m; ++i){
        cin>>v1>>v2;
        input_rank[v2]++;
        edges[v1].push_back(v2);
    }
    topology_sort(edges, input_rank, n);
}