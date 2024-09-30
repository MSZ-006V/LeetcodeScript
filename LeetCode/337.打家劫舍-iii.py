#
# @lc app=leetcode.cn id=337 lang=python
#
# [337] 打家劫舍 III
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    # 这道题是树形dp的方法，但是比较简单
    # 可以让traversal函数
    def traversal(self, root):
        if root is None:
            return [0, 0]
        
        # 1值为不偷的，2值为偷的
        # 函数返回值[val1, val2]中，val1代表不偷当前节点得到的最大金额，val2代表偷当前节点2得到的最大金额
        left1, left2 = self.traversal(root.left)
        right1, right2 = self.traversal(root.right)

        # 偷当前节点, left和right节点不能偷
        val1 = root.val + left1 + right1
        # 不偷当前节点，选最大的
        val2 = max(left1, left2) + max(right1, right2)

        return [val2, val1]
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return None
        val1, val2 = self.traversal(root)

        return max(val1, val2)

        
# @lc code=end

