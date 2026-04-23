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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dh = new ListNode(0, head);
        ListNode* cur = dh;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            int val = cur->next->val;
            if (cur->next->next->val == val) {
                cur = cur->next;
                while (cur->next && cur->next->val == val) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }

        return dh->next;
    }
};