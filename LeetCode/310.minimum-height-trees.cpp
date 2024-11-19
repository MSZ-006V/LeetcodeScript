/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
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


// @lc code=end
// 普通的BFS算法，会超时，因为计算出了每一个节点作为根节点的树高度，不适合这道题
// 会因为数据量很大的数据从而超时
// class Solution {
// public:
//     int bfs(unordered_map<int, vector<int>>& edges, int node){
//         queue<int> que;
//         que.push(node);
//         unordered_set<int> visited;
//         visited.insert(node);
//         int height = 0;

//         while(que.size() != 0){
//             int sz = que.size();
//             for(int i = 0; i < sz; ++i){
//                 int cur = que.front(); que.pop();
//                 for(auto& vertex : edges[cur]){
//                     if(visited.find(vertex) == visited.end()){
//                         que.push(vertex);
//                     }            
//                 }
//                 visited.insert(cur);
//             }
//             height++;
//         }
//         return height;

//     }
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>> es;
//         for(auto e : edges){
//             es[e[0]].push_back(e[1]);
//             es[e[1]].push_back(e[0]);
//         }
//         int min_h = INT_MAX;
//         unordered_map<int, vector<int>> result;
//         for(int i = 0; i < n; ++i){
//             int height = bfs(es, i);
//             result[height].push_back(i);
//             if(height < min_h) min_h = height;
//         }
        
//         return result[min_h];
//     }
// };
