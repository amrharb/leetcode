class Solution {
public:
    int v[1005], n, dp[1005], x;
    int solve(int i) {
        if (i == n - 1)
            return 0;
        int& ret = dp[i];
        if (~ret)
            return ret;
        ret = -1e9;
        for (int j = i + 1; j < n; j++) {
            if (v[j] - v[i] >= -x && v[j] - v[i] <= x)
                ret = max(ret, 1 + solve(j));
        }
        return ret;
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        n = nums.size(), x = target;
        for (int i = 0; i < n; i++)
            v[i] = nums[i];
        return max(-1, solve(0));
    }
};