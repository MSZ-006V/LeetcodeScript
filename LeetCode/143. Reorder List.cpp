/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // 如果链表为空或只有1、2个节点，无需重排
        if (!head || !head->next || !head->next->next) return;

        // --- 第一步：快慢指针找中点 ---
        ListNode* slow = head;
        ListNode* fast = head;
        // 注意循环条件，确保前半段长度大于等于后半段
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // --- 第二步：反转后半段链表 ---
        ListNode* cur = slow->next;
        slow->next = nullptr; // 切断前后两半链表的联系
        ListNode* pre = nullptr;
        
        while (cur) {
            ListNode* nextTemp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextTemp;
        }

        // --- 第三步：交替合并两段链表 ---
        // 此时前半段的头是 head，后半段的头是 pre
        ListNode* p1 = head;
        ListNode* p2 = pre;
        
        while (p1 && p2) {
            ListNode* next1 = p1->next;
            ListNode* next2 = p2->next;

            // 将 p2 插入到 p1 之后
            p1->next = p2;
            p2->next = next1;

            // 指针步进
            p1 = next1;
            p2 = next2;
        }
    }
};