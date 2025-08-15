/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // tc O(n), sc O(n)
        unordered_map<Node*, Node*> ht;
        ht[nullptr] = nullptr;

        Node* cur = head;
        while(cur != nullptr){ // 每一个l1会指向新创建的l2节点
            Node* newNode = new Node(cur->val);
            ht[cur] = newNode;
            cur = cur->next;
        }

        cur = head;
        while(cur != nullptr){ // 由于每一个l1指向对应的l2，通过哈希表查找l1就能找到对应的l2
        // 然后就能实现l2中的random指针也是指向l2中的某个节点的
        // 不然如果是简单的复制，l2中节点会指向l1的节点的，不符合题意
            Node* newNode = ht[cur];
            newNode->next = ht[cur->next];
            newNode->random = ht[cur->random];
            cur = cur->next;
        }

        return ht[head];

    }
};

// 优化版本，sc O(1)，tc O(n)
// 主要优化在不用使用哈希表，同时利用上了原始列表中random指针的性质，具体思路解释比较麻烦
// 可以画图来试一遍就明白了
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        Node* l1 = head;
        while (l1) { // 先创建全新的l2节点，但是把对应的l1与l2链接，而l2指向原来l1的下一个，l1的下一个指向对应的l2
            Node* l2 = new Node(l1->val);
            l2->next = l1->random;
            l1->random = l2;
            l1 = l1->next;
        }

        Node* newHead = head->random;

        l1 = head;
        while (l1) { // 利用原来l1中的random指针访问到节点，然后节点的下一个next就是对应的l2节点，通过这种方式实现类似哈希表，节省空间
            Node* l2 = l1->random;
            l2->random = (l2->next != nullptr) ? l2->next->random : nullptr;
            l1 = l1->next;
        }

        l1 = head;
        while (l1) { // 把l1和l2进行分离同时也还原，保证l1的next和l2的next是正常指向的
            Node* l2 = l1->random;
            l1->random = l2->next;
            l2->next = (l1->next != nullptr) ? l1->next->random : nullptr;
            l1 = l1->next;
        }

        return newHead;
    }
};
