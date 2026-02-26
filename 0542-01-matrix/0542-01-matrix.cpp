class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> cost(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mat[i][j]) {
                    q.push({i, j});
                }
            }
        }
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                cost[x][y] = steps;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny]) {
                        q.push({nx, ny});
                        mat[nx][ny] = 0;
                    }
                }
            }
            steps++;
        }
        return cost;
    }
};