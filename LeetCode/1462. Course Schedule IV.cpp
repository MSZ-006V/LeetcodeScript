class Solution {
public:
    vector<vector<int>> qs;
    vector<int> topology(unordered_map<int, vector<int>>& edges, vector<int>& input, int n){
        queue<int> que;
        for(int i = 0; i < n; ++i){
            if(input[i] == 0){
                que.push(i);
            }
        }

        vector<int> result;
        while(!que.empty()){
            int cur = que.front(); que.pop();
            result.insert(result.begin(), cur);
            auto edge = edges[cur];
            for(auto e : edge){

                // 每次都要刷新一下，之前的节点也同样是当前课程 e 的先修课程
                // 所以也要遍历一下
                qs[cur][e] = 1;
                for(int i = 0; i < n; ++i){
                    qs[i][e] = qs[i][e] | qs[i][cur];
                }

                input[e]--;
                if(input[e] == 0){
                    que.push(e);
                }
            }
        }

        if(result.size() != n){ // 表示无法得到拓扑排序，因为图内有环
            return {};
        }
        return result;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> input(numCourses, 0);
        unordered_map<int, vector<int>> edges;
        for(auto pre : prerequisites){
            input[pre[1]]++;
            edges[pre[0]].push_back(pre[1]);
        }
        qs = vector<vector<int>>(numCourses, vector<int>(numCourses, 0));
        vector<int> res = topology(edges, input, numCourses);
        
        vector<bool> ret;
        for(auto q : queries){
            if(qs[q[0]][q[1]]){
                ret.push_back(true);
            }
            else{
                ret.push_back(false);
            }
        }

        return ret;
    }
};