#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode{
    int index;
    int val;
    int color; // 0 = black, 1 = white
    TreeNode* left;
    TreeNode* right;
    TreeNode(int index, int val): index(index), val(val), color(0), left(nullptr), right(nullptr) {}
};

vector<int> lcms;

void dfs(vector<TreeNode*>& ws, int node, int cur_lcm){
    if(ws[node]->left == nullptr && ws[node]->right == nullptr){
        lcms[node] = cur_lcm;
        return;
    }

    lcms[node] = cur_lcm;

    if(ws[node]->left != nullptr){
        int temp_lcm = cur_lcm;
        if(ws[node]->left->color == 0){
            temp_lcm = lcm(temp_lcm, ws[node]->left->val);
        }
        dfs(ws, ws[node]->left->index, temp_lcm);
    }
    if(ws[node]->right != nullptr){
        int temp_lcm = cur_lcm;
        if(ws[node]->right->color == 0){
            temp_lcm = lcm(temp_lcm, ws[node]->right->val);
        }
        dfs(ws, ws[node]->right->index, temp_lcm);
    }
}

void find(int n, vector<TreeNode*>& ws, vector<pair<int, int>>& ops){
    for(auto op : ops){
        if(op.first == 1){
            ws[op.second - 1]->color = (ws[op.second - 1]->color + 1) % 2;
            dfs(ws, 0, ws[0]->val);
        }
        else{
            cout << lcms[op.second - 1] << endl;
        }
    }
}

int main() {
    int n, q;
    while (cin >> n >> q) { // 注意 while 处理多个 case
        vector<TreeNode*> ws; // 输入n个整数
        int val;
        for(int i = 0; i < n; ++i){
            cin >> val;
            TreeNode* node = new TreeNode(i, val);
            ws.push_back(node);
        }

        string colors;
        cin >> colors; // 输入颜色
        for(int i = 0; i < n; ++i){
            if(colors[i] == 'B'){
                ws[i]->color = 0;
            }
            else{
                ws[i]->color = 1;
            }
        }

        int u, v; // 输入边的关系
        for(int i = 0; i < n - 1; ++i){
            cin >> u >> v;
            if(ws[u - 1]->left == nullptr){
                ws[u - 1]->left = ws[v - 1];
            }
            else{
                ws[u - 1]->right = ws[v - 1];
            }
        }

        lcms = vector(n, 0);
        lcms[0] = ws[0]->val;

        int t, x; // 输入操作
        vector<pair<int, int>> ops;
        for(int i = 0; i < q; ++i){
            cin >> t >> x;
            ops.emplace_back(t, x);
        }
        dfs(ws, 0, ws[0]->val);
        find(n, ws, ops);
    }
}
// 64 位输出请用 printf("%lld")