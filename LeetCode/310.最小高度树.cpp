/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 可以使用拓扑排序，从外向内剥离节点，作为根节点的最小高度树的节点，入度一定是很大的
        // 当剥离到最后一层的时候，剩下的节点就是最小高度树的根节点集合了
        if(n == 1) return {0};
        vector<int> node_degree(n, 0);
        vector<vector<int>> es(n);
        for(auto& e : edges){
            node_degree[e[0]]++;
            node_degree[e[1]]++;
            es[e[0]].push_back(e[1]);
            es[e[1]].push_back(e[0]);
        }

        queue<int> que;
        for(int i = 0; i < n; ++i){
            if(node_degree[i] == 1){
                que.push(i);
            }
        }

        vector<int> ans;
        while(que.size() != 0){
            ans.clear();
            int sz = que.size(); 
            for(int i = 0; i < sz; ++i){
                int cur = que.front(); que.pop();
                ans.push_back(cur);
                for(auto& b : es[cur]){
                    if(--node_degree[b] == 1){
                        que.push(b);
                    }
                }
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     int BFS(unordered_map<int, vector<int>>& edges, int root, int n){
//         vector<bool> visited = vector<bool>(n, false);
//         int height = 0;
//         queue<int> que;
//         que.push(root);
//         visited[root] = true;

//         while(que.size() != 0){
//             int levelsize = que.size();
//             height++;
//             for(int i = 0; i < levelsize; ++i){
//                 int cur = que.front();que.pop();
//                 for(auto& vertex : edges[cur]){
//                     if(visited[vertex] == false){
//                         que.push(vertex);
//                         visited[vertex] = true;
//                     }
//                 }
//             }   
//         }

//         return height;
//     }
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

