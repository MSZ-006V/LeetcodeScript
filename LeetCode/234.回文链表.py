#
# @lc app=leetcode.cn id=234 lang=python
#
# [234] 回文链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def reverse_list(self, head):
        if head is None:
            return None
        pre = None
        cur = head
        while cur is not None:
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp
        return pre
    
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None:
            return None
        slow= head
        fast = head
        pre = head
        while fast and fast.next is not None:
            pre = slow
            slow = slow.next
            fast = fast.next.next
        pre.next = None

        cur1 = head
        cur2 = self.reverse_list(slow)
        # self.display(cur1)
        # print("____")
        # self.display(cur2)

        while cur1 is not None:
            if cur1.val != cur2.val:
                return False
            cur1 = cur1.next
            cur2 = cur2.next
        return True

# @lc code=end

