#
# @lc app=leetcode.cn id=143 lang=python
#
# [143] 重排链表
#

# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def reverList(self, head):
        if head is None:
            return None
        cur = head
        pre = None
        while cur is not None:
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp
        return pre
    
    def mergeList(self, cur1, cur2):
        if cur1 is None:
            return cur2
        if cur2 is None:
            return cur1
        # 由于分割的特性，cur2的长度一定是大于cur1的
        # 所以先遍历cur1
        while cur1.next is not None:
            temp1 = cur1.next
            temp2 = cur2.next
            cur1.next = cur2
            cur1.next.next = temp1

            cur1 = temp1
            cur2 = temp2
        
        # 最后要是剩下一个节点的话，一定是cur2剩一个，直接接到cur1的末尾就可以了
        if cur2 is not None:
            cur1.next = cur2 
        

    def display(self, head):
        if head is None:
            return None
        cur = head
        while cur is not None:
            print(cur.val)
            cur = cur.next
        
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        # 先使用快慢指针，fast和slow和pre
        # 当fast跑到链表末尾的时候，slow就正好在链表的中间
        # 然后把slow指针就指到第二个链表，把slow指针对应的链表置反
        # pre指针用于截断第二个链表
        # 然后再把head和slow指向的2个链表进行合并，从head取一个再从slow取一个

        if head is None:
            return None
        if head.next is None:
            return head
        slow = head
        fast = head
        pre = head
        while fast and fast.next is not None:
            pre = slow
            slow = slow.next
            fast = fast.next.next
        pre.next = None

        cur1 = head
        cur2 = self.reverList(slow)
        # self.display(cur1)
        # print("----")
        # self.display(cur2)
        self.mergeList(cur1, cur2)
# @lc code=end

