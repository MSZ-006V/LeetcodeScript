/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:

    vector<int> topology_sort(unordered_map<int, vector<int>>& edges
    , vector<int>& input_rank, int n){
        vector<int> result;
        queue<int> que;
        for(int i = 0; i < input_rank.size(); ++i){
            if(input_rank[i] == 0){
                que.push(i);
            }
        }

        while(que.size() != 0){
            int cur = que.front();que.pop();
            result.insert(result.begin(), cur);
            vector<int>& cur_edge = edges[cur]; // 这样子写减少内存占用

            for(int i = 0; i < cur_edge.size(); ++i){
                input_rank[cur_edge[i]]--;
                if(input_rank[cur_edge[i]] == 0){
                    que.push(cur_edge[i]);
                }
            }
        }
        if(result.size() != n){ // 表示无法得到拓扑排序，因为图内有环
            return {};
        }
        return result;

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> input_rank(numCourses, 0);
        unordered_map<int, vector<int>> edges;
        for(int i = 0; i < prerequisites.size(); ++i){
            input_rank[prerequisites[i][1]]++;
            edges[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> result = topology_sort(edges, input_rank, numCourses);
        return result;
    }
};
// @lc code=end

