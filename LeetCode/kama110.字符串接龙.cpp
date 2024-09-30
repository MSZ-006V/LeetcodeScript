#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include <string>

using namespace std;

int main(){
    int n;
    std::cin>>n;
    
    string beginStr = "";
    string endStr = "";
    string str = "";
    
    std::cin>>beginStr>>endStr;
    unordered_set<string> strlist;
    for(int i = 0; i < n; ++i){
        cin>>str;
        strlist.insert(str);
    }
    unordered_map<string, int> visited;
    queue<string> queue;
    queue.push(beginStr);
    visited.insert({beginStr, 1});
    
    // 使用bfs进行搜索，因为bfs一旦搜索到终点，一定就是最短路径
    // 如果使用dfs搜索，还需要记录最大的路径
    while(!queue.empty()){
        string old_str = queue.front();
        queue.pop();
        int path = visited[old_str];
        
        for(int i = 0; i < old_str.size(); ++i){
            string new_str = old_str;
            for(int j = 0; j < 26; ++j){
                new_str[i] = j + 'a';
                if(new_str == endStr){
                    cout << path + 1 << endl;
                    return 0;
                }
                if(strlist.find(new_str) != strlist.end() && visited.find(new_str) == visited.end()){
                    visited.insert({new_str, path + 1});
                    queue.push(new_str);
                }
            }
        }
    }
    for(const auto&pair : visited)
        cout << pair.first << pair.second << endl;
    cout << 213 << endl;
    
}