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
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* cur = head;
        while (cur->next) {
            if (cur->next->val >= 0) {
                cur = cur->next;
            }
            else {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                temp->next = head;
                head = temp;
            }
        }

        return head;
    }
};

// 链表题目中最忌讳的就是 node->next = head 而此时 node 本身就是 head。这就像是左脚踩右脚原地起飞，在内存里会形成一个环