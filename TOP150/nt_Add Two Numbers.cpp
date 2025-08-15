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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // tc O(n), sc O(1)
        // leetcode 445中，链表存储的数字是倒序的，这里是正序的，所以可以直接相加
        // 如果是倒序的就先reverse一下再加，一样的
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* dh = new ListNode();
        ListNode* cur = dh;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            if(l1) carry += l1->val;
            if(l2) carry += l2->val;

            cur->next = new ListNode(carry % 10);
            carry = carry / 10;
            cur = cur->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return dh->next;
    }
};
