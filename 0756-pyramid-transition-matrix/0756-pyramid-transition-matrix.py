class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        validTops = defaultdict(set)
        for pattern in allowed:
            validTops[(pattern[0], pattern[1])].add(pattern[2])

        @cache
        def check(pattern):
            if len(pattern) == 1:
                return True
            for i in range(len(pattern) - 1):
                if (pattern[i], pattern[i + 1]) not in validTops:
                    return False

            @cache
            def backTrack(i, choice):
                if i == len(pattern) - 1:
                    return check(choice)

                for top in validTops[(pattern[i], pattern[i + 1])]:
                    if backTrack(i + 1, choice + top):
                        return True
                return False

            return backTrack(0, "")

        return check(bottom)
