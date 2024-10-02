/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
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
        // 这题思路使用最小堆，首先使用自定义的lambda函数，创建一个专门用于链表的最小堆
        // 然后把k个链表的头节点全部都入队，每次取出一个最小的进行连接，如果有后续节点
        // 就把后续节点再压入队列
        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> que;
        for(auto head : lists){
            if(head){
                que.push(head);
            }
        }
        ListNode* dummyH =  = new ListNode();
        ListNode* cur = dummyH;

        while(que.size() != 0){
            ListNode* node = que.top(); que.pop();
            if(node->next){
                que.push(node->next);
            }
            cur->next = node;
            cur = cur->next;
        }

        return dummyH->next;
    }
};
// @lc code=end

