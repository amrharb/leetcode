const int mod = 1e9 + 7;
class Solution {
public:
    int dfs(int node, int par, vector<vector<int>>& adj) {
        int ret = 0;
        for (auto ch : adj[node]) {
            if (ch == par)
                continue;
            ret = max(ret, 1 + dfs(ch, node, adj));
        }
        return ret;
    }
    int bpow(int n, int x) {
        return !x ? 1
                  : 1LL * bpow(1LL * n * n % mod, x >> 1) * (x & 1 ? n : 1) %
                        mod;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return bpow(2, dfs(1, 0, adj) - 1);
    }
};