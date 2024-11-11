vector<int> topology(
    unordered_map<int, vector<int>>& edges,
    vector<int> input_rank,
    int numCourses){
        vector<int> result;
        queue<int> que;

        for(int i = 0; i < input_rank.size(); ++i){
            if(input_rank[i] == 0){
                que.push(i);
            }
        }

        while(que.size() != 0){
            int cur = que.front(); que.pop();
            result.insert(result.begin(), cur);
            vector<int>& cur_edge = edges[cur];

            for(int i = 0; i < cur_edge.size(); ++i){
                input_rank[cur_edge[i]]--;
                if(input_rank[cur_edge[i]] == 0){
                    que.push(cur_edge[i]);
                }
            }
        }

        if(result.size() != numCourses){
            return {};
        }
        return result;
    }

vector<int> findorder(int numCourses, vector<vector<int>>& prerequisites){
    vector<int> input_rank(numCourses, 0);
    unordered_map<int, vector<int>> edges;
    for(int i = 0; i < prerequisites.size(); ++i){
        input_rank[prerequisites[i][1]]++;
        edges[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
}