const int N = 1e3 + 5;
class Solution {
public:
    int pref[N][N];
    int get_prefix(int l1, int r1, int l2, int r2) {
        return pref[l2][r2] - pref[l2][r1 - 1] - pref[l1 - 1][r2] +
               pref[l1 - 1][r1 - 1];
    }
    int maximalRectangle(vector<vector<char>>& v) {
        int n = v.size(), m = v[0].size();
        for (int i = 1; i <= n; i++) {
            pref[i][0] = pref[0][i] = 0;
            for (int j = 1; j <= m; j++) {
                pref[i][j] = (v[i - 1][j - 1] == '1') + pref[i][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] += pref[i - 1][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < n; k++) {
                    int l = 0, r = m - j;
                    while (l <= r) {
                        int mid = (l + r) / 2;
                        if (get_prefix(i, j, i + k, j + mid) ==
                            (k + 1) * (mid + 1))
                            l = mid + 1;
                        else
                            r = mid - 1;
                    }
                    ans = max(ans, (k + 1) * l);
                }
            }
        }
        return ans;
    }
};