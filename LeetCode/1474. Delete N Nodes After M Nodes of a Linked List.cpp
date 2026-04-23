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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* cur = head;
        ListNode* last = head;
        while (cur != nullptr) {
            // initialize mCount to m and nCount to n
            int mCount = m, nCount = n;
            // traverse m nodes
            while (cur != nullptr && mCount != 0) {
                last = cur;
                cur = cur->next;
                mCount--;
            }
            // traverse n nodes
            while (cur != nullptr && nCount != 0) {
                cur = cur->next;
                nCount--;
            }
            // delete n nodes
            last->next = cur;
        }
        return head; 
    }
};