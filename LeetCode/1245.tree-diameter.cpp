/*
 * @lc app=leetcode id=1245 lang=cpp
 *
 * [1245] Tree Diameter
 */

// @lc code=start
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        if(edges.size() == 0) return 0;
        unordered_map<int, vector<int>> lines;
        for(auto edge : edges){
            lines[edge[0]].push_back(edge[1]);
            lines[edge[1]].push_back(edge[0]);
        }

        int result = 0;
        DFS(lines, edges[0][0], -1, result);

        return result;
    }

    int DFS(unordered_map<int, vector<int>>& lines, int node, int parent, int& res){
        vector<int>& new_n = lines[node];
        int fmax = 0, smax = 0; // 记录DFS搜索记录中最大的两个数
        for(auto n : new_n){
            if(n == parent) continue;
            int child_res = DFS(lines, n, node, res);

            if(child_res > fmax){
                smax = fmax;
                fmax = child_res;
            }
            else if(child_res > smax){
                smax = child_res;
            }

            res = max(res, fmax + smax); // 两个数加起来和res比较，取最大的
        } 

        return fmax + 1; // 如果检索到叶子节点，fmax=0，所以直接返回1就行，fmax代表的是最大的
    }
};
// @lc code=end

