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
    // ListNode* reverse(ListNode* head){
    //     ListNode* pre = nullptr;
    //     ListNode* cur = head;
    //     while(cur){
    //         ListNode* temp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = temp;
    //     }

    //     return pre;
    // }
    ListNode* reverseList(ListNode* head) {
        // tc O(n), sc O(1)
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while(cur != nullptr){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        return pre;
    }
};
