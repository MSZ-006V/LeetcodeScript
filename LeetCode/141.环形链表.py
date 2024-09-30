#
# @lc app=leetcode.cn id=141 lang=python
#
# [141] 环形链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 通过设置一个快慢指针，慢指针一次走一步，快指针一次走两步
        # 如果存在环，那么两个指针一定会相遇，否则不存在环
        # 这题比较简单的原因是不需要找到环的入口
        fast = head
        slow = head
        while fast and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                return True
        return False
# @lc code=end

