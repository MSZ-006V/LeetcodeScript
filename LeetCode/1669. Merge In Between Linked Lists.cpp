class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *preA = list1, *afterB = list1;
        
        // 1. 找到第 a-1 个节点
        for (int i = 0; i < a - 1; ++i) preA = preA->next;
        
        // 2. 找到第 b 个节点 (为了方便，多走一步到 b 的 next 也就是 afterB)
        afterB = preA;
        for (int i = 0; i <= b - a + 1; ++i) afterB = afterB->next;
        
        // 3. 找到 list2 的末尾
        ListNode* last2 = list2;
        while (last2->next) last2 = last2->next;
        
        // 4. 重新缝合
        preA->next = list2;      // a-1 指向 list2 头
        last2->next = afterB;    // list2 尾指向 b+1
        
        return list1;
    }
};