class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans = "";
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                string temp = str + ch;
                if (isKTimesRepeted(temp, s, k)) {
                    ans = temp;
                    q.push(temp);
                }
            }
        }
        return ans;
    }
    bool isKTimesRepeted(string skk, string src, int k) {
        int p = 0, counter = 0;
        for (char ch : src) {
            if (ch == skk[p]) {
                if (++p == skk.size()) {
                    p = 0;
                    if (++counter == k)
                        return true;
                }
            }
        }
        return false;
    }
};