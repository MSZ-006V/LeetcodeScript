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
    ListNode* removeNodes(ListNode* head) {
        list<ListNode*> st;
        ListNode* cur = head;
        while (cur) {
            while (!st.empty() && st.back()->val < cur->val) {
                st.pop_back();
            }
            st.push_back(cur);
            cur = cur->next;
        }
        ListNode* dh = new ListNode();
        cur = dh;
        while (!st.empty()) {
            cur->next = st.front(); st.pop_front();
            cur = cur->next;
        }

        return dh->next;
    }
};