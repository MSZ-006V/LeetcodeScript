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
    bool hasCycle(ListNode* head) {
        // tc O(n), sc O(n)
        ListNode* cur = head;
        unordered_set<ListNode*> lset;

        while(cur != nullptr){
            if(lset.find(cur) != lset.end()){
                return true;
            }
            lset.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};
