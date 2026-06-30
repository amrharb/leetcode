class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), ans = 0;
        vector<int> nxt(3, n);
        for (int i = n - 1; i >= 0; i--) {
            nxt[s[i] - 'a'] = i;
            ans += n - max({nxt[0], nxt[1], nxt[2]});
        }
        return ans;
    }
};