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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // tc O(n * k), sc O(n * k)
        priority_queue<int, vector<int>, std::greater<>> pq;
        for(ListNode* node : lists){
            ListNode* cur = node;
            while(cur != nullptr){
                pq.push(cur->val);
                cur = cur->next;
            }
        }

        ListNode* dh = new ListNode();
        ListNode* cur = dh;
        while(!pq.empty()){
            ListNode* node = new ListNode(pq.top());
            pq.pop();
            cur->next = node;
            cur = cur->next;
        }

        return dh->next;
    }
};

class Solution {
public:
    // tc O(nlogk), sc O(k)
    ListNode* mergeKLists(vector<ListNode*>& lists) {\
        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(auto head : lists){
            if(head){
                pq.push(head);
            }
        }

        ListNode* dh = new ListNode();
        ListNode* cur = dh;
        while(!pq.empty()){
            ListNode* node = pq.top();pq.pop();
            if(node->next) pq.push(node->next);
            cur->next = node;
            cur = cur->next;
        }

        return dh->next;
    }
};