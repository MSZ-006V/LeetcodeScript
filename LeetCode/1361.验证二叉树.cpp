class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> in_degress(n, 0);
        vector<vector<int>> edges(n);
        
        for(int i = 0; i < n; ++i){
            int u = leftChild[i];
            int v = rightChild[i];

            // 检查左孩子
            if(u != -1) {
                in_degress[u]++;
                if(in_degress[u] > 1) return false; // 入度检查
                edges[i].push_back(u);
            }
            // 检查右孩子
            if(v != -1) {
                in_degress[v]++;
                if(in_degress[v] > 1) return false; // 入度检查
                edges[i].push_back(v);
            }
            // 这里的 edges[i].size() 其实就是有效的出度
            if(edges[i].size() > 2) return false; 
        }

        // 寻找唯一的根
        int root = -1;
        int root_cnt = 0;
        for(int i = 0; i < n; ++i){
            if(in_degress[i] == 0) {
                root = i;
                root_cnt++;
            }
        }
        if(root_cnt != 1 || root_cnt != 1) return false; // 必须有且仅有一个根

        // BFS 验证连通性
        queue<int> que;
        vector<int> visited(n, 0);
        visited[root] = 1;
        que.push(root);

        int count = 0; // 用于统计遍历到的节点数
        while(!que.empty()){
            int cur = que.front(); que.pop();
            count++;
            for(auto nei : edges[cur]){
                if(visited[nei]) return false; // 发现重复访问，即存在环
                visited[nei] = 1;
                que.push(nei);
            }
        }

        return count == n; 
    }
};