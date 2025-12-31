class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        unordered_map<char, char> mp{{'(', ')'}, {'[', ']'}, {'{', '}'}};
        for (int i = 0; i < n; i++) {
            if (!st.empty() && mp[st.top()] == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return !st.size();
    }
};