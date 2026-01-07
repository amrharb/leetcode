# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        dict = defaultdict(int)

        def dfs(root):
            if not root:
                dict[root] = 0
                return 0
            dict[root] = root.val + dfs(root.left) + dfs(root.right)
            return dict[root]

        summ = dfs(root)
        mod = 10 ** 9 + 7

        def solve(root):
            if not root:
                return 0
            ans = max(
                dict[root] * (summ - dict[root]), solve(root.left), solve(root.right)
            )
            return ans

        return solve(root) % mod
