class Solution {
public:
    int maxarea(vector<vector<int>>& grid, int start_i, int end_i, int start_j,
                int end_j) {
        if (start_i > end_i || start_j > end_j)
            return 0;
        int l1, l2, r1, r2;
        l1 = r1 = -1;
        r2 = l2 = INT_MAX;
        int found = 0;
        for (int i = start_i; i <= end_i; i++) {
            for (int j = start_j; j <= end_j; j++) {
                if (grid[i][j] == 1) {
                    l1 = max(l1, i);
                    l2 = min(l2, i);
                    r1 = max(r1, j);
                    r2 = min(r2, j);
                    found = 1;
                }
            }
        }
        if (found == 0)
            return 0;
        return (l1 - l2 + 1) * (r1 - r2 + 1);
    }
    int minimumSum(vector<vector<int>>& grid) {

        int ans = INT_MAX;
        int n = grid.size();
        if (n == 0)
            return 0;
        int one, two, three;
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            one = maxarea(grid, 0, i, 0, m - 1);
            for (int j = 0; j < m; j++) {
                two = maxarea(grid, i + 1, n - 1, 0, j);
                three = maxarea(grid, i + 1, n - 1, j + 1, m - 1);
                ans = min(ans, one + two + three);
            }
        }

        for (int i = 0; i < n; i++) {
            one = maxarea(grid, i, n - 1, 0, m - 1);
            for (int j = 0; j < m; j++) {
                two = maxarea(grid, 0, i - 1, 0, j);
                three = maxarea(grid, 0, i - 1, j + 1, m - 1);
                ans = min(ans, one + two + three);
            }
        }

        for (int j = 0; j < m; j++) {
            one = maxarea(grid, 0, n - 1, 0, j);
            for (int i = 0; i < n; i++) {
                two = maxarea(grid, 0, i, j + 1, m - 1);
                three = maxarea(grid, i + 1, n - 1, j + 1, m - 1);
                ans = min(ans, one + two + three);
            }
        }

        for (int j = 0; j < m; j++) {
            one = maxarea(grid, 0, n - 1, j, m - 1);
            for (int i = 0; i < n; i++) {
                two = maxarea(grid, 0, i, 0, j);
                three = maxarea(grid, i + 1, n - 1, 0, j);
                ans = min(ans, one + two + three);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                one = maxarea(grid, 0, i, 0, m - 1);
                two = maxarea(grid, i + 1, j, 0, m - 1);
                three = maxarea(grid, j + 1, n - 1, 0, m - 1);
                ans = min(ans, one + two + three);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                one = maxarea(grid, 0, n - 1, 0, i);
                two = maxarea(grid, 0, n - 1, i + 1, j);
                three = maxarea(grid, 0, n - 1, j + 1, m - 1);
                ans = min(ans, one + two + three);
            }
        }
        return ans;
    }
};