/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution {
public:
    int dfs(vector<vector<pair<int, int>>>& edges, int x, int parent){
        int res = 0;
        for(auto& e : edges[x]){
            // 是为了防止重复访问，因为是一个无向图，要防止重复访问，比如目前x是0，这条边是从(4,0)访问过来的，parent是4
            // 当遍历0的节点时候，遇到(0,4)就会跳过，防止在两个节点之间来来回回
            if(e.first == parent) continue;
            res += e.second + dfs(edges, e.first, x);
        }
        return res;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> edges(n);
        for(auto edge : connections){
            // 把原来正向的权值记为1，反向的权值记为0，这样子方便在dfs中直接统计距离
            edges[edge[0]].push_back(make_pair(edge[1], 1));
            edges[edge[1]].push_back(make_pair(edge[0], 0));
        }
        // 初始parent定义为-1就行
        // 从节点0开始访问，可以访问到的全部都是反向的，而这些边的权值都是1，把这些边的权值
        // 全部加起来，就知道要把多少条边反向了
        return dfs(edges, 0, -1);
    }
};
// @lc code=end

