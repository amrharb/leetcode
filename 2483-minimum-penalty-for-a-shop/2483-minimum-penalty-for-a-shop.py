class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        rem_customers = customers.count("Y")
        min_penalty = rem_customers
        pref_penalty = 0
        index = 0
        for i in range(n):
            if customers[i] == "Y":
                rem_customers -= 1
            else:
                pref_penalty += 1
            if min_penalty > pref_penalty + rem_customers:
                min_penalty = pref_penalty + rem_customers
                index = i + 1
        return index
