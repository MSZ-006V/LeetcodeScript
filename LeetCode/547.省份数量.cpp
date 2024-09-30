/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    int n = 201;
    vector<int> father = vector<int>(n, 0);
    
    void __init__(){
        for(int i = 0; i < n; ++i){
            father[i] = i;
        }
    }
    int find(int u){
        if(father[u] == u){
            return u;
        }
        else{
            return father[u] = find(father[u]);
        }
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
        father[v] = u;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        __init__();
        int verticse_num = isConnected.size();
        int union_num = verticse_num; // 最初的省份个数，即独立集合的个数
        // 随着循环的不断进行，有城市不断并入集合，独立集合就减少了
        for(int i = 0; i < verticse_num; ++i){
            for(int j = i + 1; j < verticse_num; ++j){
                if(isConnected[i][j] == 1){
                    if(isSame(i, j) == false){ 
                        // 如果这条边的两个顶点都不在集合，同时这条边是连通的，那么就进入if执行
                        union_num -= 1; // 表示要新加入顶点，即独立集合的个数就-1
                        join(i, j); // 把边加入集合
                    }
                }
            }
        }
        return union_num;
    }
};
// @lc code=end

