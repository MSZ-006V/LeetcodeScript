/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 1; // 计算出链表的长度
        ListNode* iter = head;
        for (; iter->next != nullptr; iter = iter->next) {
            n++;
        }

        int add = n - k % n; // 计算出链表最后rotate后，最后的头节点应该在的位置
        if (add == n) {
            return head;
        }
        
        iter->next = head; // 此时iter指向的是链表的最后一个节点，将尾节点和头结点相连接，得到一个环
        // 然后再移动 add 次，从该位置断开，就得到了rotate后应该的结果
        while (add--) {
            iter = iter->next;
        }
        ListNode* ret = iter->next;
        iter->next = nullptr;
        return ret;
    }
};