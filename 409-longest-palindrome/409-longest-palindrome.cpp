class Solution {
public:
    int longestPalindrome(string s) {
        int cnt=0;
        bool odd=0;
        map<char,int>mp;
        for(auto&it:s)mp[it]++;
        for(auto it:mp){
            cnt+=it.second/2;
            odd|=(it.second&1);
        }
        return cnt*2+odd;
    }
};