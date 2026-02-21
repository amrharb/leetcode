class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        res = []
        stk = []
        n = len(asteroids)
        for i in range(n):
            if asteroids[i] > 0:
                stk.append(asteroids[i])
            else:
                while stk and stk[-1] < abs(asteroids[i]):
                    stk.pop()
                if stk and stk[-1] == abs(asteroids[i]):
                    stk.pop()
                elif not stk:
                    res.append(asteroids[i])

        for element in stk:
            res.append(element)
        return res
