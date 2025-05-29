class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        auto g1 = build(edges1, n);
        auto g2 = build(edges2, m);

        int c2 = 0;
        for (int i = 0; i < m; i++) {
            c2 = max(c2, dfs(g2, i, -1, k - 1));
        }
        vector<int> ans(n, c2);
        for (int i = 0; i < n; i++) {
            ans[i] += dfs(g1, i, -1, k);
        }
        return ans;
    }
    vector<vector<int>> build(vector<vector<int>>& edges, int sz) {
        vector<vector<int>> v(sz);
        for (auto x : edges) {
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        return v;
    }
    int dfs(vector<vector<int>>& v, int a, int pa, int k) {
        if (k < 0)
            return 0;
        int cnt = 1;
        for (auto x : v[a]) {
            if (x != pa) {
                cnt += dfs(v, x, a, k - 1);
            }
        }
        return cnt;
    }
};