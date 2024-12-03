/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    stack<Node*> st;

    void pushNode(Node* node){
        while(node != nullptr){
            st.push(node);
            node = node->left;
        }
    }

    Node* treeToDoublyList(Node* root) {
        // time complexity is O(n)
        这题直接用数的节点当做双向链表的节点，一个prev一个next
        使用的是中序遍历的迭代版
        if(root == nullptr) return root;

        pushNode(root);

        Node* head = new Node(0);
        Node* prev = head;
        Node* cur;

        while(!st.empty()){
            cur = st.top(); st.pop();
            pushNode(cur->right);

            prev->right = cur;
            cur->left = prev;
            prev = cur;
        }

        // 最后把头和尾连起来
        head->right->left = cur;
        cur->right = head->right;

        return head->right;



        return nullptr;
    }
};

// 中序遍历的递归版本，推荐还是用递归来写，代码简洁也方便记忆

// class Solution {
// public:
//     Node* treeToDoublyList(Node* root) {
//         if (!root) return NULL;

//         Node *head = NULL, *pre = NULL;

//         inorder(root, pre, head);

//         pre->right = head;
//         head->left = pre;

//         return head;
//     }

//     void inorder(Node* node, Node*& pre, Node*& head) {
//         if (!node) return;

//         inorder(node->left, pre, head);

//         if (!head) {
//             head = node;
//             pre = node;
//         } 
//         else {
//             pre->right = node;
//             node->left = pre;
//             pre = node;
//         }

//         inorder(node->right, pre, head);
//     }
// };
// @lc code=end

