/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 */

// @lc code=start
class Solution {
// 简单的并查集查找，公式做题就是快！
private:
    vector<int> f;
public:
    void init(int n){
        f = vector<int>(n, 0);
        for(int i = 0; i < n; ++i){
            f[i] = i;
        }
    }

    int find(int u){
        if(f[u] == u) return u;
        else return f[u] = find(f[u]);
    }

    bool isSame(int u, int v){
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        f[v] = u;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // time complexity is O(n), space complexity is O(n)
        // 对于n的顶点，如果想连接成树最少需要n - 1条边，所以如果边的个数小于n - 1，不用判断了肯定连不成
        if(edges.size() < n - 1) return false;
        init(n);
        for(auto e : edges){
            if(isSame(e[0], e[1])){ // 如果两个点在集合里，直接返回false，否则最后返回true
                return false;
            }
            join(e[0], e[1]);
        }
        return true;
    }
};
// @lc code=end

