#include <vector>
using namespace std;

struct PrefixSum2D {
    int n, m;
    vector<vector<long long>> ps;

    PrefixSum2D(const vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        ps.assign(n + 1, vector<long long>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ps[i][j] = grid[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] -
                           ps[i - 1][j - 1];
            }
        }
    }

    long long query(int x1, int y1, int x2, int y2) {
        x1++;
        y1++;
        x2++;
        y2++;
        return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] +
               ps[x1 - 1][y1 - 1];
    }
};

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        PrefixSum2D pref(grid);
        for (int i = 0; i + 1 < n; i++) {
            if (pref.query(0, 0, i, m - 1) ==
                pref.query(i + 1, 0, n - 1, m - 1)) {
                return true;
            }
        }
        for (int j = 0; j + 1 < m; j++) {
            if (pref.query(0, 0, n - 1, j) ==
                pref.query(0, j + 1, n - 1, m - 1)) {
                return true;
            }
        }
        return false;
    }
};