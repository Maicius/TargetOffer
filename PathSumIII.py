# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if root == None:
            return 0

        return self.find_path(root, sum) + self.pathSum(root.left, sum) + self.pathSum(root.right, sum)
        
    def find_path(self, root, val):
        res = 0
        if not root:
            return res
        if root.val == val:
            res += 1
        res += self.find_path(root.left, val - root.val)
        res += self.find_path(root.right, val - root.val)
        return res