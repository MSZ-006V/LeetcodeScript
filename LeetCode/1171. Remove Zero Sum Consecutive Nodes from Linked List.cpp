class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        unordered_map<int, ListNode*> sumMap;
        int sum = 0;

        // 第一遍遍历：记录每一个前缀和对应的最后一个节点
        // 如果 sum 再次出现，说明中间一段抵消成了 0，map 会自动更新为最右侧的节点
        for (ListNode* cur = dummy; cur != nullptr; cur = cur->next) {
            sum += cur->val;
            sumMap[sum] = cur;
        }

        // 第二遍遍历：利用 map 直接跳过和为 0 的区间
        sum = 0;
        for (ListNode* cur = dummy; cur != nullptr; cur = cur->next) {
            sum += cur->val;
            // cur->next 直接指向该前缀和最后一次出现位置的下一个节点
            // 这样中间那些和为 0 的节点就被逻辑删除了
            cur->next = sumMap[sum]->next;
        }

        return dummy->next;
    }
};