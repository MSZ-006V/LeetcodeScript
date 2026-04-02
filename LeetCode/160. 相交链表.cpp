/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 假设A和B都是有长度的链表，都不为空
        int len_a = 0, len_b = 0;
        ListNode* cur = headA;
        while(cur != nullptr){
            len_a++;
            cur = cur->next;
        }

        cur = headB;
        while(cur != nullptr){
            len_b++;
            cur = cur->next;
        }
        if(len_a > len_b){
            int diff = len_a - len_b;
            while(diff > 0){
                headA = headA->next;
                diff--;
            }
        }
        else if(len_a < len_b){
            int diff = len_b - len_a;
            while(diff > 0){
                headB = headB->next;
                diff--;
            }
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headB;
    }
};
// 有三种方法
// 1. 双指针：不需要显式计算深度，直接套用链表找交点的 trick：定义指针 a 指向 p，指针 b 指向 q。a 向上爬，爬到根节点后跳转到 q 的起点继续爬。b 向上爬，爬到根节点后跳转到 p 的起点继续爬。当 a == b 时，相遇点就是 LCA。原理：路径 A + 路径 B 的总长度是相等的（$pathP + root + pathQ = pathQ + root + pathP$）。
// 2. 对齐高度：从 p 开始，顺着 parent 一路爬到根节点，把路径上经过的所有节点存入 unordered_set
//     - 从 q 开始向上爬，爬到的第一个在 set 中出现的节点，就是它们的 LCA
// 3. 哈希集合法 (最直观)：从 p 开始，顺着 parent 一路爬到根节点，把路径上经过的所有节点存入 unordered_set
//     - 从 q 开始向上爬，爬到的第一个在 set 中出现的节点，就是它们的 LCA