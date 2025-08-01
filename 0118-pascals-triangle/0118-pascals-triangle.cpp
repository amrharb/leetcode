class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0, k; j <= i; j++) {
                if (!j || j == i)
                    k = 1;
                else
                    k = dp[i - 1][j - 1] + dp[i - 1][j];
                dp[i].push_back(k);
            }
        }
        return dp;
    }
};