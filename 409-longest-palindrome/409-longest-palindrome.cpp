class Solution {
public:
    int longestPalindrome(string s) {
        int cnt=0;
        bool odd=0;
        map<char,int>mp;
        for(auto&it:s)mp[it]++;
        for(char i='a';i<='z';i++){
            cnt+=mp[i]/2;
            odd|=(mp[i]&1);
        }
        for(char i='A';i<='Z';i++){
            cnt+=mp[i]/2;
            odd|=(mp[i]&1);
        }
        return cnt*2+odd;
    }
};