class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=s.size(),mx=0;
        map<char,int>mp;
        while(l<n){
            while(r<n&&!mp[s[r]]){
                mp[s[r++]]++;
            }
            mx=max(mx,r-l);
            mp[s[l]]--;
            l++;
        }
        return mx;
    }
};