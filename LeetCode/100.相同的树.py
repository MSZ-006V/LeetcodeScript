#
# @lc app=leetcode.cn id=100 lang=python
#
# [100] 相同的树
#

# @lc code=start
# Definition for a binary tree node.
import collections
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def __init__(self):
        self.r1 = []
        self.r2 = []
    def traversal(self, root):
        if root is None:
            return None
        
        self.r1.append(root.val)
        left = self.traversal
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if not p and not q:
            return True
        if p and not q:
            return False
        if q and not p:
            return False
        queue1 = collections.deque([p])
        queue2 = collections.deque([q])
        output1 = [p.val]
        output2 = [q.val]
        while queue1:
            for _ in range(len(queue1)):
                cur = queue1.popleft()
                if cur.left:
                    queue1.append(cur.left)
                    output1.append(cur.left.val)
                else:
                    output1.append(None)
                if cur.right:
                    queue1.append(cur.right)
                    output1.append(cur.right.val)
                else:
                    output1.append(None)

        while queue2:
            for _ in range(len(queue2)):
                cur = queue2.popleft()
                if cur.left:
                    queue2.append(cur.left)
                    output2.append(cur.left.val)
                else:
                    output2.append(None)
                if cur.right:
                    queue2.append(cur.right)
                    output2.append(cur.right.val)
                else:
                    output2.append(None)

        return output1 == output2
# @lc code=end

