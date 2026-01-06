# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        q = deque()
        q.append(root)
        mx = ans = - 10 ** 9
        level = 1
        while q:
            sz = len(q)
            summ = 0
            for i in range(sz):
                curr = q.popleft()
                summ += curr.val
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            if summ > mx:
                mx = summ
                ans = level
            level += 1

        return ans
