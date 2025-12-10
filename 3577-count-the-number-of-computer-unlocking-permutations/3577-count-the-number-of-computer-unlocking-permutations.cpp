class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        if (*min_element(complexity.begin() + 1, complexity.end()) <=
            complexity[0])
            return 0;
        int n = complexity.size(), fact = 1, mod = 1e9 + 7;
        for (int i = 1; i < n; i++)
            fact = 1LL * fact * i % mod;
        return fact;
    }
};