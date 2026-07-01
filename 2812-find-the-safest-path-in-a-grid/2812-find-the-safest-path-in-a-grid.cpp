int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
class Solution {
public:
    bool check(vector<vector<int>>& grid, vector<int> dist, int n, int m,
               int z) {
        if (dist[0] < z)
            return 0;
        queue<int> q;
        q.push(0);
        bitset<405 * 405> vis;
        vis[0] = 1;
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            int i = p / m, j = p % m;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && y >= 0 && x < n && y < m && !vis[x * m + y] &&
                    dist[x * m + y] >= z) {
                    vis[x * m + y] = 1;
                    q.push(x * m + y);
                }
            }
        }
        return vis[(n - 1) * m + (m - 1)];
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<int> q;
        vector<int> dist(n * m, 1e9);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j])
                    q.push(i * m + j), dist[i * m + j] = 0;
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            int i = p / m, j = p % m;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && y >= 0 && x < n && y < m &&
                    dist[x * m + y] > dist[p] + 1) {
                    dist[x * m + y] = dist[p] + 1;
                    q.push(x * m + y);
                }
            }
        }
        int l = 1, r = 1e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(grid, dist, n, m, mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l - 1;
    }
};