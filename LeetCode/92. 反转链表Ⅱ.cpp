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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // tc O(n), sc O(1)
        // 比较巧妙，使用的是头插法进行旋转，不要移动pre指针和cur指针，只移动cur的next指针
        ListNode* dh = new ListNode(0, head);
        ListNode* pre = dh;

        for(int i = 1; i < left; ++i){
            pre = pre->next;
        }

        ListNode* cur = pre->next;
        for(int i = 0; i < right - left; ++i){
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }

        return dh->next;
    }
};

// [1,2,3,4,5], left = 2, right = 4
// 此时left就是节点1，right就是节点5，因此翻转2,3,4
// 得到的结果是1,4,3,2,5
// 所以使用1作为pre节点，翻转right-left次
// pre可以当成是一个dh的节点，使用头插法，插入pre和pre->next的节点就可以了！