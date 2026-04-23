class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head); // 用哨兵节点简化代码逻辑
        ListNode* node0 = &dummy;
        ListNode* node1 = head;
        while (node1 && node1->next) { // 至少有两个节点
            ListNode* node2 = node1->next;
            ListNode* node3 = node2->next;

            node0->next = node2; // 0 -> 2
            node2->next = node1; // 2 -> 1
            node1->next = node3; // 1 -> 3

            node0 = node1; // 下一轮交换，0 是 1
            node1 = node3; // 下一轮交换，1 是 3
        }
        return dummy.next; // 返回新链表的头节点
    }
};

// https://leetcode.cn/problems/swap-nodes-in-pairs/solutions/2374872/tu-jie-die-dai-di-gui-yi-zhang-tu-miao-d-51ap/
