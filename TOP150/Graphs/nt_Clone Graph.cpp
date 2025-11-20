/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> ht;
        return dfs(node, ht);
    }

    Node* dfs(Node* node, map<Node*, Node*>& ht){
        // dfs方法
        if(node == nullptr) return nullptr;
        // 如果ht没有这个键就会返回0，就会继续向下执行
        if(ht.count(node)) return ht[node];

        Node* copy = new Node(node->val);
        ht[node] = copy;

        for(Node* nei : node->neighbors){
            copy->neighbors.push_back(dfs(nei, ht));
        }

        return copy;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // BFS方法
        if (!node) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;
        oldToNew[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (Node* nei : cur->neighbors) { // 遍历邻居
                if (oldToNew.find(nei) == oldToNew.end()) { // 如果邻居没有克隆过，先克隆
                    oldToNew[nei] = new Node(nei->val);
                    q.push(nei);
                }
                // 把相邻的点压入（nei）
                oldToNew[cur]->neighbors.push_back(oldToNew[nei]);
            }
        }
        return oldToNew[node];
    }
};
