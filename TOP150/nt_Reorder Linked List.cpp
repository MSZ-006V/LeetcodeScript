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
    ListNode* reverseList(ListNode* node){
        ListNode* cur = node;
        ListNode* pre = nullptr;

        while(cur != nullptr){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        return pre;
    }

    void mergeList(ListNode* node1, ListNode* node2){
        while(node1 != nullptr && node2 != nullptr){
            ListNode* temp1 = node1->next;
            ListNode* temp2 = node2->next;
            node1->next = node2;
            node2->next = temp1;

            node1 = temp1;
            node2 = temp2;
        }
    }
    void reorderList(ListNode* head) {
        
        ListNode* l1 = head;
        ListNode* l2 = head;

        while(l2 != nullptr && l2->next != nullptr && l2->next->next != nullptr){
            l1 = l1->next;
            l2 = l2->next->next;
        }
        
        l2 = l1->next;
        l1->next = nullptr;
        
        l2 = reverseList(l2);
        mergeList(head, l2);

        return;
    }
};
