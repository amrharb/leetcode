class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 1;

        vector<vector<int>> rowPS(n, vector<int>(m + 1, 0));
        vector<vector<int>> colPS(n + 1, vector<int>(m, 0));
        vector<vector<int>> diagPS(n, vector<int>(m, 0));
        vector<vector<int>> rdiagPS(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowPS[i][j + 1] = rowPS[i][j] + grid[i][j];
                colPS[i + 1][j] = colPS[i][j] + grid[i][j];
                diagPS[i][j] = grid[i][j] + (i > 0 && j > 0 ? diagPS[i - 1][j - 1] : 0);
                rdiagPS[i][j] = grid[i][j] + (i > 0 && j + 1 < m ? rdiagPS[i - 1][j + 1] : 0);
            }
        }

        auto check = [&](int x1, int y1, int x2, int y2) {
            int target = rowPS[x1][y2 + 1] - rowPS[x1][y1];

            for (int i = x1; i <= x2; i++)
                if (rowPS[i][y2 + 1] - rowPS[i][y1] != target)
                    return false;

            for (int j = y1; j <= y2; j++)
                if (colPS[x2 + 1][j] - colPS[x1][j] != target)
                    return false;

            int d1 = diagPS[x2][y2] - (x1 > 0 && y1 > 0 ? diagPS[x1 - 1][y1 - 1] : 0);
            if (d1 != target) return false;

            int d2 = rdiagPS[x2][y1] - (x1 > 0 && y2 + 1 < m ? rdiagPS[x1 - 1][y2 + 1] : 0);
            if (d2 != target) return false;

            return true;
        };

        for (int x1 = 0; x1 < n; x1++) {
            for (int y1 = 0; y1 < m; y1++) {
                for (int x2 = x1; x2 < n; x2++) {
                    int y2 = y1 + (x2 - x1);
                    if (y2 < m && check(x1, y1, x2, y2))
                        ans = max(ans, x2 - x1 + 1);
                }
            }
        }

        return ans;
    }
};
