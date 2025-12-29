class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        validTops = defaultdict(set)
        for pattern in allowed:
            validTops[(pattern[0], pattern[1])].add(pattern[2])

        @lru_cache
        def check(pattern):
            if len(pattern) == 1:
                return True
            choices = list()
            choices.append("")
            for i in range(len(pattern) - 1):
                if (pattern[i], pattern[i + 1]) not in validTops:
                    return False
                temp = list(choices)
                choices = []
                for top in validTops[(pattern[i], pattern[i + 1])]:
                    for choice in temp:
                        nw = choice + top
                        choices.append(nw)

            for choice in choices:
                if check(choice):
                    return True
            return False

        return check(bottom)
