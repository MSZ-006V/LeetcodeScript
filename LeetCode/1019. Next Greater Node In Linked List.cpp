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
    vector<int> nextLargerNodes(ListNode* head) {
        // 类似739，使用单调栈即可
        unordered_set<ListNode*> sets;
        stack<ListNode*> st;
        ListNode* cur = head;
        while (cur != nullptr) {
            while (!st.empty() && st.top()->val < cur->val) {
                st.top()->val = cur->val;
                sets.insert(st.top());
                st.pop();
            }
            st.push(cur);
            cur = cur->next;
        }

        vector<int> res;
        cur = head;
        while (cur) {
            if (sets.find(cur) != sets.end()) {
                res.push_back(cur->val);
            }
            else {
                res.push_back(0);
            }
            cur = cur->next;
        }

        return res;
    }
};