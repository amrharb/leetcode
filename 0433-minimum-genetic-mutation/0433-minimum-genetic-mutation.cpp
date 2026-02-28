class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = start.size();
        unordered_map<string, bool> vis;
        queue<string> q;
        q.push(start);
        vis[start] = 1;
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto cur = q.front();
                q.pop();
                if (cur == end)
                    return steps;
                for (auto& it : bank) {
                    if (vis[it])
                        continue;
                    int cnt = 0;
                    for (int i = 0; i < n; i++) {
                        cnt += (it[i] != cur[i]);
                    }
                    if (cnt == 1)
                        q.push(it), vis[it] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};
