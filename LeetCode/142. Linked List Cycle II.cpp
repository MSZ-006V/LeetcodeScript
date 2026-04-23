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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;

        unordered_set<ListNode*> sets;
        ListNode* node = head;

        while (node) {
            if (sets.find(node) != sets.end()) return node;
            sets.insert(node);
            node = node->next;
        }

        return nullptr;
    }
};