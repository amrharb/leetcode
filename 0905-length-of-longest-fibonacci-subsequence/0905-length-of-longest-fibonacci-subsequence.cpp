class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), mx = 0;
        vector<vector<int>>dp(n,vector<int>(n));
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (idx.count(arr[i] - arr[j]) && idx[arr[i] - arr[j]] < j) {
                    dp[i][j] = dp[j][idx[arr[i]-arr[j]]] + 1;
                    if (dp[i][j] > 2)
                        mx = max(mx, dp[i][j]);
                } else {
                    dp[i][j] = 2;
                }
            }
            idx[arr[i]] = i;
        }
        return mx;
    }
};