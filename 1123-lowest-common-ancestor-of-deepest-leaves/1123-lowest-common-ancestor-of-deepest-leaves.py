# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            if not root:
                return [root, 0]
            curr = [root, 0]
            left = dfs(root.left)
            right = dfs(root.right)
            if left[1] > right[1]:
                curr[0] = left[0]
            elif left[1] < right[1]:
                curr[0] = right[0]
            curr[1] = max(left[1], right[1]) + 1
            return curr

        return dfs(root)[0]
