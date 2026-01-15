#include <iostream>
#include <vector>

// g++ test.cpp -o test
// ./test.exe

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* bulidList(vector<int>& v){
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    for(int x : v){
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return head->next;
}

ListNode* reverse(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur){
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

void display(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
}

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& v){
    vector<TreeNode*> nodes(v.size(), nullptr);
    for(int i = 0; i < v.size(); ++i){
        nodes[i] = new TreeNode(v[i]);
    }
    for(int i = 0; i < v.size(); ++i){
        int l = 2 * i + 1, r = 2 * i + 2;
        if(l < v.size()) nodes[i]->left = nodes[l];
        if(r < v.size()) nodes[i]->right = nodes[r];
    }

    return nodes[0];
}

void displayTree(TreeNode* root){
    if(!root) return;
    cout << root->val << " ";
    displayTree(root->left);
    displayTree(root->right);
}

int main(){
    vector<int> ListNode_v = {1, 2, 3, 4, 5};
    ListNode* head = bulidList(ListNode_v);
    display(head);
    cout << endl;
    ListNode* rev_head = reverse(head);
    display(rev_head);
    cout << endl;

    vector<int> TreeNode_v = {1, 2, 3, 4, 5, 6, 7};
    //       1
    //   2       3
    // 4   5   6   7
    TreeNode* root = buildTree(TreeNode_v);
    displayTree(root);
    cout << endl;

    return 0;
}