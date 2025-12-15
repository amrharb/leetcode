class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = set()
        candidates.sort()
        for i in range(len(candidates) - 1, target - 1, -1):
            if candidates[i] == candidates[i - target]:
                candidates.pop(i)

        n = len(candidates)

        def backTrack(i, curr_sum, curr_lst):
            if curr_sum > target:
                return
            if curr_sum == target:
                ans.add(tuple(curr_lst))
                return
            if i == n:
                return
            for j in range(i,n):
                if j > i and candidates[i] == candidates[i-1]:
                    continue
                curr_sum += candidates[j]
                curr_lst.append(candidates[j])
                backTrack(j + 1, curr_sum, curr_lst)
                curr_sum -= candidates[j]
                curr_lst.pop()

        backTrack(0, 0, [])
        return list(ans)