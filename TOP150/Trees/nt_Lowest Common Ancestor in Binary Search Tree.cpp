// leetcode 236 Lowest common ancestor 最近公共祖先

class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 这个查找方式比较巧妙，用到了BST的性质，左小右大，可以学习一下
        if(!root || !p || !q){
            return nullptr;
        }

        if(max(p->val, q->val) < root->val){
            return LCA(root->left, p, q);
        } 
        else if(min(p->val, q->val) > root->val){
            return LCA(root->right, p, q);
        } 
        else{
            return root;
        }
    }
};

class MinHeap{
private:
    vector<int> h;
public:
    void push(int val){
        h.push_back(val);
        siftUp(h.size() - 1);
    }
    void pop(){
        int n = h.size();
        swap(h[0], h[n - 1]);
        h.pop_back();
        siftDown(0);
    }   
    int top(){
        return h[0];
    }

    void siftUp(int i){
        while(i > 0){
            int p = (i - 1) / 2;
            if(h[p] <= h[i]) break;
            swap(h[p], h[i]);
            i = p;
        }
    }

    void siftDown(int i){
        int n = h.size();
        while(true){
            int l = 2 * i + 1, r = 2 * i + 2;
            int smallest = i;
            if(l < n && h[smallest] < h[l]) smallest = l;
            if(r < n && h[smallest] < h[r]) smallest = r;
            if(smallest == i) break;
            swap(h[i], h[smallest]);
            i = smallest;
        }
    }
};