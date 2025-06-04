class Solution {
public:
    string answerString(string s, int m) {
        if (m == 1)
            return s;
        string ans = "A";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            ans = max(ans, s.substr(i, n - m + 1));
        }
        return ans;
    }
};