const int N = 1e5 + 5;
class Solution {
public:
    vector<pair<int, int>> adj[N];
    vector<int> nodes[N];
    int vis[N], id = 0, comp[N];
    int cur;
    void dfs(int u) {
        vis[u] = id;
        nodes[id].push_back(u);
        for (auto& [next, w] : adj[u]) {
            if (!vis[next]) {
                dfs(next);
            }
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        id = 0;
        for (int i = 0; i < n; i++)
            vis[i] = 0, adj[i].clear(), nodes[i].clear(), comp[i] = -1;
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ++id;
                dfs(i);
            }
        }
        for (int i = 1; i <= id; i++) {
            comp[i] = -1;
            for (auto& it : nodes[i]) {
                for (auto& [a, w] : adj[it]) {
                    comp[i] &= w;
                }
            }
            cout << comp[i] << ' ';
        }
        cout << '\n';
        int q = query.size();
        vector<int> ans;
        for (auto& qury : query) {
            if (qury[0] == qury[1])
                ans.push_back(0);
            else if (vis[qury[0]] == vis[qury[1]])
                ans.push_back(comp[vis[qury[0]]]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};