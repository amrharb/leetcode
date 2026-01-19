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
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int k = i; k < n; k++) {
                vector<int> col(m);
                for (int j = 0; j < m; j++) {
                    col[j] = pref[k][j] - (i ? pref[i - 1][j] : 0);
                }
                int sum = 0, diff = k - i + 1;
                for (int j = 0; j < m; j++) {
                    sum += col[j];
                    if (j >= diff)
                        sum -= col[j - diff];
                    if (j >= diff - 1 && sum <= threshold) {
                        mx = max(mx, diff);
                        break;
                    }
                }
            }
        }
        return mx;
    }
};