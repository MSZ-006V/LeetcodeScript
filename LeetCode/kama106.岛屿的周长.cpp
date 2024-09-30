#include<iostream>
#include<vector>

using namespace std;

int area = 0;
int n,m = 0;
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int Count_area(vector<vector<int>>& graph, int x, int y){
    int length = 0;
    for(int i = 0; i < 4; ++i){
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m){
            length++;
            continue;
        }
        if(graph[next_x][next_y] == 0){
            length++;
        }
    }
    return length;
}

int main(){
    // easy question
    cin>>n>>m;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin>>graph[i][j];
        }
    }
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < m; ++j){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(graph[i][j] == 1){
                area += Count_area(graph, i, j);
            }
        }
    }
    cout << area << endl;
    return 0;
}