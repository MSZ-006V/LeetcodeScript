#
# @lc app=leetcode.cn id=116 lang=python
#
# [116] 填充每个节点的下一个右侧节点指针
#

# @lc code=start
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
import collections
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if root is None:
            return None
        queue = collections.deque([root])
        while queue:
            level = []
            for _ in range(len(queue)):
                cur = queue.popleft()
                if len(queue) != 0:
                    cur.next = queue[0]
                if cur.left:
                    level.append(cur.left)
                if cur.right:
                    level.append(cur.right)
            for i in range(len(level)):
                queue.append(level[i])
        return root
# @lc code=end

