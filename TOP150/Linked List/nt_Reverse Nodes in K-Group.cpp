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
    ListNode* getKthNode(ListNode* cur, int k){
        while(cur && k > 0){
            cur = cur->next;
            k--;
        }
        return cur;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // tc O(n), sc O(1)
        // 实际比较复杂，操作的指针数目比较多，基本原理比较好理解
        // 就是使用一堆变量存储某些位置，最后再进行更新，保证循环的正确
        // 比较重要的变量有groupNext, groupPrev
        ListNode* dh = new ListNode(0, head);
        ListNode* groupPrev = dh;

        while(true){
            ListNode* kth = getKthNode(groupPrev, k);
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
