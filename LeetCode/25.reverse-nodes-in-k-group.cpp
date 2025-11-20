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
    // 一共有 kth, groupPrev, groupNext, pre, cur 五个不同的指针
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dh = new ListNode(0, head);
        ListNode* groupPrev = dh;

        while (true) {
            // 找到本组的起点 cur 和 tail（可能不足 k 个）
            ListNode* cur = groupPrev->next;
            ListNode* tail = cur;
            int count = 0;

            while (tail && count < k) {
                tail = tail->next;
                count++;
            }

            // 没有更多节点，结束
            if (count == 0) break;

            // 这里 tail 就是下一组的开头
            ListNode* pre = tail;

            // 反转本组（实际反转 count 个，不一定 == k）
            while (count--) {
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }

            // 本组新的头是 pre，本组新的尾是 groupPrev->next
            ListNode* temp = groupPrev->next;
            groupPrev->next = pre;
            groupPrev = temp;
        }

        return dh->next;
    }
};
// @lc code=end

