class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;

        unordered_map<string, int> idx;
        vector<string> words;

        auto addWord = [&](const string& s) {
            if (!idx.count(s)) {
                idx[s] = (int)words.size();
                words.push_back(s);
            }
        };

        for (int i = 0; i < (int)original.size(); i++) {
            addWord(original[i]);
            addWord(changed[i]);
        }

        int totalWords = (int)words.size();

        vector<vector<long long>> dist(totalWords,
                                       vector<long long>(totalWords, INF));
        for (int i = 0; i < totalWords; i++)
            dist[i][i] = 0;

        for (int i = 0; i < (int)original.size(); i++) {
            int from = idx[original[i]];
            int to = idx[changed[i]];
            dist[from][to] = min(dist[from][to], (long long)cost[i]);
        }

        for (int mid = 0; mid < totalWords; mid++) {
            for (int from = 0; from < totalWords; from++) {
                if (dist[from][mid] >= INF)
                    continue;
                for (int to = 0; to < totalWords; to++) {
                    if (dist[mid][to] >= INF)
                        continue;
                    dist[from][to] =
                        min(dist[from][to], dist[from][mid] + dist[mid][to]);
                }
            }
        }

        int n = (int)source.size();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        unordered_set<int> validLen;
        for (auto& w : words)
            validLen.insert((int)w.size());

        for (int i = 0; i < n; i++) {
            if (dp[i] >= INF)
                continue;

            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            for (int len : validLen) {
                if (i + len > n)
                    continue;

                string a = source.substr(i, len);
                string b = target.substr(i, len);

                if (!idx.count(a) || !idx.count(b))
                    continue;

                int u = idx[a];
                int v = idx[b];

                if (dist[u][v] >= INF)
                    continue;

                dp[i + len] = min(dp[i + len], dp[i] + dist[u][v]);
            }
        }

        return (dp[n] >= INF) ? -1 : dp[n];
    }
};