/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        // 应该可以通过一个unordered_map，记录所有node节点，然后按照正常的排序方法进行排序即可
        // 官方做法是使用归并排序和快慢指针的方法，先分割链表，然后再合并
        if(head == nullptr){
            return nullptr;
        }
        vector<int> result;
        ListNode* cur = head;
        while(cur != nullptr){
            result.push_back(cur->val);
            cur = cur->next;
        }
        sort(result.begin(), result.end());
        cur = head;
        int index = 0;
        while(cur != nullptr){
            cur->val = result[index];
            index++;
            cur = cur->next;
        }
        return head;
    }
};
// @lc code=end

