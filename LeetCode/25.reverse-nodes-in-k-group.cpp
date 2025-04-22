/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
class Solution {
public:
    ListNode* getNode(ListNode* cur, int k){
        while(cur && k > 0){
            cur = cur->next;
            k--;
        }

        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dh = new ListNode(0, head);
        ListNode* groupPrev = dh;

        while(true){
            ListNode* kth = getNode(groupPrev, k);
            if(kth == nullptr) break;

            ListNode* groupNext = kth->next;
            ListNode* pre = kth->next; // 表示当前的指针头应该指向的是下一组的头，因为反转后
            ListNode* cur = groupPrev->next;

            while(cur != groupNext){
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }

            ListNode* temp = groupPrev->next;
            groupPrev->next = kth; // dh, 1, 2, 3在翻转后，实际上变成了dh 3 2 1，所以要更新，保证头尾正确，1的下一个就是下一个翻转group的起始了 
            groupPrev = temp;
        }

        return dh->next;
    }
};

// 不够k个也翻转
// ListNode* reverseAllKGroup(ListNode* head, int k) {
//     ListNode* dummy = new ListNode(0, head);
//     ListNode* groupPrev = dummy;

//     while (true) {
//         // 不用提前判断 kth 是不是空
//         ListNode* cur = groupPrev->next;
//         ListNode* tail = cur;
//         int count = 0;
//         while (tail && count < k) {
//             tail = tail->next;
//             count++;
//         }

//         // 实际数量可能 < k
//         if (count == 0) break;

//         ListNode* prev = tail;
//         while (count--) {
//             ListNode* temp = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = temp;
//         }

//         ListNode* temp = groupPrev->next;
//         groupPrev->next = prev;
//         groupPrev = temp;
//     }

//     return dummy->next;
// }
// @lc code=end

