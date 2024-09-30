#
# @lc app=leetcode.cn id=129 lang=python
#
# [129] 求根节点到叶节点数字之和
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def __init__(self):
        self.results = []
        self.sum = 0

    def traversal(self, root, result):
        result.append(root.val)
        if root.left is None and root.right is None:
            self.results.append(''.join(map(str, result)))
            return
        
        if root.left:
            self.traversal(root.left, result)
            result.pop()
        if root.right:
            self.traversal(root.right, result)
            result.pop()

    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        self.traversal(root, [])
        for result in self.results:
            self.sum += int(result)
        return self.sum
# @lc code=end

