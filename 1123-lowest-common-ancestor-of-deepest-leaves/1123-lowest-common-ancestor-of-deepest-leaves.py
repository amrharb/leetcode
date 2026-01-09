# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            curr = [root, 0]
            if root.left:
                curr = dfs(root.left)
            if root.right:
                ret = dfs(root.right)
                if ret[1] > curr[1]:
                    curr = ret
                elif ret[1] == curr[1]:
                    curr = [root, curr[1]]
            curr[1] += 1
            return curr

        return dfs(root)[0]
