/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool topology_sort(unordered_map<int, vector<int>> edges, vector<int> input_rank, int n){
        vector<int> result;
        queue<int> que;
        for(int i = 0; i < input_rank.size(); ++i){
            if(input_rank[i] == 0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int cur = que.front();que.pop();
            result.push_back(cur);
            vector<int>& nodes = edges[cur];
            
            for(int i = 0; i < nodes.size(); ++i){
                input_rank[nodes[i]]--;
                if(input_rank[nodes[i]] == 0){
                    que.push(nodes[i]);
                }
            }
        }

        // for(int i = 0; i < result.size(); ++i){
        //     cout << result[i] << ' ';
        // }

        if(result.size() != n){ // 如果result的长度不为n，说明有向图中有环，自然返回false
            return false;
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 最经典的拓扑排序，对于一个有向图，是否可以把这个图转换为一个线性的序列进行输出
        // 这就是拓扑排序的用处
        vector<int> input_rank(numCourses, 0);
        unordered_map<int, vector<int>> edges;
        for(int i = 0; i < prerequisites.size(); ++i){
            input_rank[prerequisites[i][1]]++;
            edges[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // for(int i = 0; i < numCourses; ++i){
        //     cout << i << ": " << input_rank[i] << ' ';
        // }
        bool result = topology_sort(edges, input_rank, numCourses);
        return result;
    }
};
// @lc code=end

