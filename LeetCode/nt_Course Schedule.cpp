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

        return result.size() == n? true : false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> input_rank(numCourses, 0);
        unordered_map<int, vector<int>> edges;
        for(int i = 0; i < prerequisites.size(); ++i){
            input_rank[prerequisites[i][1]]++;
            edges[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        bool result = topology_sort(edges, input_rank, numCourses);
        return result;
    }
};
