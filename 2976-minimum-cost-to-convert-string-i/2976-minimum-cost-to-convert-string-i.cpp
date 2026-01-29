class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& org,
                          vector<char>& chng, vector<int>& cost) {
        vector<vector<int>> c(26, vector<int>(26, 1e9));
        for (int i = 0; i < org.size(); i++) {
            c[org[i] - 'a'][chng[i] - 'a'] =
                min(c[org[i] - 'a'][chng[i] - 'a'], cost[i]);
        }
        for (int i = 0; i < 26; i++)
            c[i][i] = 0;
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (c[s[i] - 'a'][t[i] - 'a'] == 1e9)
                return -1;
            ans += c[s[i] - 'a'][t[i] - 'a'];
        }
        return ans;
    }
};