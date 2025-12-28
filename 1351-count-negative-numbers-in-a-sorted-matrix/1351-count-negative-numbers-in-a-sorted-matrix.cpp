class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = m - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (v[i][mid] >= 0)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            cnt += m - l;
        }
        return cnt;
    }
};