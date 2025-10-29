class Solution {
public:
    vector<int> topologySort(unordered_map<int, vector<int>>& edges, vector<int>& input_rank, int num){
        vector<int> result;
        queue<int> que;

        for(int i = 0; i < num; ++i){
            if(input_rank[i] == 0){
                que.push(i);
            }
        }

        while(!que.empty()){
            int cur = que.front(); que.pop();
            result.push_back(cur);
            vector<int>& edge = edges[cur];

            for(int i = 0; i < edge.size(); ++i){
                input_rank[edge[i]]--;
                if(input_rank[edge[i]] == 0){
                    que.push(edge[i]);
                }
            }
        }

        reverse(result.begin(), result.end());

        return result.size() == num? result:std::vector<int>();
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>input_rank(numCourses, 0);
        unordered_map<int, vector<int>> edges;

        for(int i = 0; i < prerequisites.size(); ++i){
            input_rank[prerequisites[i][1]]++;
            edges[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        return topologySort(edges, input_rank, numCourses);
    }
};
