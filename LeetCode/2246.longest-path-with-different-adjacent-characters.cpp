/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 */

// @lc code=start
class Solution {
public:
    // 和124比较类似，这题有以下思想：找前两个最大值，树形dp
    int dfs(unordered_map<int, vector<int>>& ht, string& s, int node, int parent, int& res){
        int first_max_len = 0;
        vector<int>& nodes = ht[node];

        for(auto e : nodes){
            // 防止重复循环遍历
            if(e == parent) continue;
            // 遍历所有node的子节点，然后找出两个最大的值作为路径相加，
            // 并且返回的时候直接+1，代表连接到当前节点node的话，距离就是+1
            // 先计算出结果，然后再考虑是否要进行更新最大值
            // 当两个字符不一样才进行更新
            int second_max_len = dfs(ht, s, e, node, res) + 1;
            if(s[e] != s[node]){
                // 用全局变量更新，然后记录当前的最大值
                res = max(res, first_max_len + second_max_len);
                first_max_len = max(first_max_len, second_max_len);
            }
        }
        // 向上返回当前节点node的最大值
        return first_max_len;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int, vector<int>> ht;
        for(int i = 1; i < n; ++i){
            ht[parent[i]].push_back(i);
        }

        int ans = 0;
        dfs(ht, s, 0, -1, ans);
        
        // 求出来的ans是边的个数，题目要的是点的个数，所以就是边的个数 + 1就是点的个数
        return ans + 1;
    }
};
// @lc code=end

