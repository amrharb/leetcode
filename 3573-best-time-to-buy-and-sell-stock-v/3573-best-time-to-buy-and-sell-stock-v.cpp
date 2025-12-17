class Solution {
public:
    int n;
    vector<int> p;
    long long NEG = -(long long)1e18;

    vector<vector<vector<long long>>> dp;
    vector<vector<vector<bool>>> vis;

    long long solve(int i, int rem, int last) {
        if (i == n) {
            return (last == 2 ? 0 : NEG);
        }

        if (vis[i][rem][last])
            return dp[i][rem][last];

        vis[i][rem][last] = true;

        long long ret = solve(i + 1, rem, last);

        if (last == 0) {
            ret = max(ret, -p[i] + solve(i + 1, rem, 2));
        }
        else if (last == 1) {
            ret = max(ret, p[i] + solve(i + 1, rem, 2));
        }
        else if (rem > 0) {
            ret = max({
                ret,
                p[i] + solve(i + 1, rem - 1, 0),
                -p[i] + solve(i + 1, rem - 1, 1)
            });
        }

        return dp[i][rem][last] = ret;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        p = prices;
        n = p.size();

        dp.assign(n, vector<vector<long long>>(k + 1, vector<long long>(3)));
        vis.assign(n, vector<vector<bool>>(k + 1, vector<bool>(3, false)));

        return solve(0, k, 2);
    }
};
