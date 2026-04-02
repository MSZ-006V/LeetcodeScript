/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

// 实际上是160 相交链表，找链表的交点
// 利用了定理
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        // tc O(h)，sc O(1)，h 是树的高度，最坏情况下树是链状的，h 就是 n
        Node* pointer_p = p;
        Node* pointer_q = q;

        while(pointer_p != pointer_q){
            pointer_p = pointer_p->parent;
            if(pointer_p == nullptr) pointer_p = q;

            pointer_q = pointer_q->parent;
            if(pointer_q == nullptr) pointer_q = p;
        }

        return pointer_p;
    }
};