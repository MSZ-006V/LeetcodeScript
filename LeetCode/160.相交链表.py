#
# @lc app=leetcode.cn id=160 lang=python
#
# [160] 相交链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        size_a = 0
        size_b = 0
        cur = headA
        while cur is not None:
            size_a += 1
            cur = cur.next
        cur = headB
        while cur is not None:
            size_b += 1
            cur = cur.next

        cur_a = headA
        cur_b = headB
        
        if size_a > size_b:
            skip = size_a - size_b
            while skip > 0:
                cur_a = cur_a.next
                skip -= 1
        else:
            skip = size_b - size_a
            while skip > 0:
                cur_b = cur_b.next
                skip -= 1

        while cur_a is not None:
            if cur_a == cur_b:
                return cur_a
            cur_a = cur_a.next
            cur_b = cur_b.next
        return None
# @lc code=end

