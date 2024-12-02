/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

// @lc code=start
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
    ListNode* reverseList(ListNode* root){
        if(root == nullptr || root->next == nullptr) return root;

        ListNode* pre = nullptr;
        ListNode* cur = root;
        while(cur != nullptr){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    ListNode* addTwo(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode* cur = new ListNode();
        ListNode* dhead = cur;

        while(l1 || l2 || carry != 0){
            // 上面循环的条件不会保证l1和l2一定是非空的，所以这里一定要判断
            if(l1 != nullptr) carry += l1->val;
            if(l2 != nullptr) carry += l2->val;

            cur->next = new ListNode(carry % 10);
            carry = carry / 10;
            cur = cur->next;
            // 同样的，这里也需要判断是否为空，免得访问越界
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        // 因为结构中定义ListNode(int x, ListNode *next) : val(x), next(next) {}
        // 所以要返回dhead的下一个节点，因为在上面dhead = cur
        return dhead->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 时间复杂度O(n), 空间复杂度O(1)
        // 先把两个链表全部倒过来，然后相加，在把结果链表倒回去就可以
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* l3 = addTwo(l1, l2);
        l3 = reverseList(l3);

        return l3;
    }
};
// @lc code=end

