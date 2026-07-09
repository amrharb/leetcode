struct DSU {
    vector<int> sz, p;
    DSU(int n) {
        sz.resize(n);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }
    int find(int u) { return p[u] = (u == p[u] ? u : find(p[u])); }
    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)
            return false;
        if (sz[u] > sz[v])
            swap(u, v);
        p[u] = v;
        sz[v] += sz[u];
        return true;
    }
    bool isSame(int u, int v) { return find(u) == find(v); }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        DSU dsu(n);
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                dsu.join(i, i - 1);
        }
        vector<bool> ans;
        for (auto query : queries) {
            ans.push_back(dsu.isSame(query[0], query[1]));
        }
        return ans;
    }
};