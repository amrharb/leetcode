int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, 1, -1};
const int N = 505;
class Solution {
public:
    int dp[N][N][4][3][2];
    vector<vector<int>> v;
    int n, m;
    bool valid(int i, int j, int last) {
        if (!(i >= 0 && j >= 0 && i < n && j < m))
            return false;
        if (last == 1 && v[i][j] == 2)
            return true;
        if (last == 2 && v[i][j] == 0)
            return true;
        if (last == 0 && v[i][j] == 2)
            return true;
        return false;
    }

    int solve(int i, int j, int k, int last, bool f) {
        if (!valid(i, j, last))
            return 0;
        int& ret = dp[i][j][k][last][f];
        if (~ret)
            return ret;
        ret = 1 + solve(i + dx[k], j + dy[k], k, v[i][j], f);
        if (!f) {
            int l = (k + 1) % 4;
            ret = max(ret, 1 + solve(i + dx[l], j + dy[l], l, v[i][j], 1));
        }
        return ret;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        v = grid;
        memset(dp, -1, sizeof dp);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 1)
                    continue;
                for (int k = 0; k < 4; k++) {
                    mx = max(mx,
                             1 + solve(i + dx[k], j + dy[k], k, grid[i][j], 0));
                }
            }
        }
        return mx;
    }
};