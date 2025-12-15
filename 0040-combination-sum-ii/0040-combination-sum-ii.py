class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        for i in range(len(candidates) - 1, target - 1, -1):
            if candidates[i] == candidates[i - target]:
                candidates.pop(i)

        ans = []
        n = len(candidates)

        def backTrack(i, curr_sum, curr_lst):
            if curr_sum > target:
                return
            if curr_sum == target:
                ans.append(list(curr_lst))
                return
            if i == n:
                return
            for j in range(i, n):
                if j > i and candidates[j] == candidates[j - 1]:
                    continue
                curr_lst.append(candidates[j])
                backTrack(j + 1, curr_sum + candidates[j], curr_lst)
                curr_lst.pop()

        backTrack(0, 0, [])
        return ans
