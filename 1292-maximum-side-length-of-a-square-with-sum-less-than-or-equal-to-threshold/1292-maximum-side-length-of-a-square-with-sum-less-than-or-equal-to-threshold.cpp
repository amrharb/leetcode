class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i)
                    pref[i][j] += pref[i - 1][j];
                pref[i][j] += mat[i][j];
            }
        }
        auto check = [&](int x) {
            for (int i = 0; i + x - 1 < n; i++) {
                int k = i + x - 1, sum = 0;
                for (int j = 0; j < m; j++) {
                    sum += pref[k][j] - (i ? pref[i - 1][j] : 0);
                    if (j >= x)
                        sum -= pref[k][j - x] - (i ? pref[i - 1][j - x] : 0);
                    if (j >= x - 1 && sum <= threshold) {
                        return true;
                    }
                }
            }
            return false;
        };
        int l = 1, r = min(n, m);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};