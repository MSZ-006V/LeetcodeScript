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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // tc O(n), sc O(1)
        ListNode* dh = new ListNode(0, head);
        ListNode* pre = dh;
        ListNode* cur = head;
        int size = 0;
        while(cur != nullptr){
            size++;
            cur = cur->next;
        }
        n = size - n;
        cur = head;

        while(n > 0){
            n--;
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;

        return dh->next;
    }
};
