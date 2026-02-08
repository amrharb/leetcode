# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        INF = 1e9

        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left) + 1
            right = dfs(root.right) + 1
            if abs(left - right) <= 1:
                return max(left, right)
            return INF

        return True if dfs(root) < INF else False
