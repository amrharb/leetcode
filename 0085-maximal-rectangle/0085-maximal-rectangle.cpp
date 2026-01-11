class Solution {
public:
    int maximalRectangle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = (grid[i - 1][j - 1] == '1') + pref[i - 1][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int sum = 0;
                for (int k = 1; k <= m; k++) {
                    if (pref[j][k] - pref[i - 1][k] == (j - i+1))
                        sum++;
                    else
                        sum=0;
                    ans = max(ans, sum * (j - i + 1));
                }
            }
        }
        return ans;
    }
};