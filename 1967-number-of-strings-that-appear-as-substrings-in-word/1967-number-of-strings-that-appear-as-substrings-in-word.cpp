class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (auto pattern : patterns) {
            if (~(int)word.find(pattern))
                cnt++;
        }
        return cnt;
    }
};