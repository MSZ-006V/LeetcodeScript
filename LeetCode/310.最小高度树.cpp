/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    int BFS(unordered_map<int, vector<int>>& edges, int root, int n){
        vector<bool> visited = vector<bool>(n, false);
        int height = 0;
        queue<int> que;
        que.push(root);
        visited[root] = true;

        while(que.size() != 0){
            int levelsize = que.size();
            height++;
            for(int i = 0; i < levelsize; ++i){
                int cur = que.front();que.pop();
                for(auto& vertex : edges[cur]){
                    if(visited[vertex] == false){
                        que.push(vertex);
                        visited[vertex] = true;
                    }
                }
            }   
        }

        return height;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 类似暴力法，遍历所有根节点，求出树的高度，超时了
        // unordered_map<int, vector<int>> eds;
        // for(auto& edge : edges){
        //     eds[edge[0]].push_back(edge[1]);
        //     eds[edge[1]].push_back(edge[0]);
        // }

        // for(auto& it : eds){
        //     vector<int> temp = it.second;
        //     cout << it.first << ": ";
        //     for(auto elem : temp){
        //         cout << elem << ' ';
        //     }
        //     cout << endl;
        // }

        // std::map<int, vector<int>> result;
        // for(int i = 0; i < n; ++i){
        //     int height = BFS(eds, i, n);
        //     result[height].push_back(i);
        // }

        // return result.begin()->second;

        // 拓扑排序
    }
};
// @lc code=end

