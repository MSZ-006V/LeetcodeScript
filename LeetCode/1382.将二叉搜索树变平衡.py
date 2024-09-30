#
# @lc app=leetcode.cn id=1382 lang=python
#
# [1382] 将二叉搜索树变平衡
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
        self.result = []
    def traversal(self, root):
        if root is None:
            return None
        
        self.traversal(root.left)
        self.result.append(root.val)
        self.traversal(root.right)
    def builtBST(self, nums, left, right):
        if left > right:
            return None
        mid = left + ((right - left) // 2)
        root_node = TreeNode(nums[mid])
        root_node.left = self.builtBST(nums, left, mid - 1)
        root_node.right = self.builtBST(nums, mid + 1, right)
        return root_node
    def balanceBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        # 本题思路，先通过对原来的二叉搜索树进行中序遍历，得到一个递增数组
        # 再通过使用递增数组构造平衡二叉搜索树的方法，得到新的BST，返回
        if root is None:
            return None
        self.traversal(root)
        BST = self.builtBST(self.result, 0, len(self.result) - 1)
        return BST
        
# @lc code=end

