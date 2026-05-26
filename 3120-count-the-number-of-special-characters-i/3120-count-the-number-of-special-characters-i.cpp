class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        map<char, int> mp;
        for (auto& it : word)
            mp[it]++;
        for (char i = 'a'; i <= 'z'; i++) {
            cnt += (mp[i] && mp[toupper(i)]);
        }
        return cnt;
    }
};