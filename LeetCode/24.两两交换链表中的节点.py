#
# @lc app=leetcode.cn id=24 lang=python
#
# [24] 两两交换链表中的节点
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        
        dummy_head = ListNode(0, head)
        current = dummy_head
        while current.next and current.next.next is not None:
            temp1 = current.next
            temp2 = current.next.next.next

            current.next = temp1.next
            current.next.next = temp1
            current.next.next.next = temp2
            
            current = current.next.next

        return dummy_head.next
# @lc code=end

