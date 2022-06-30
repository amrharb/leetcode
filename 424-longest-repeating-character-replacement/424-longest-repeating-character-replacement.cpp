class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        map<char,int>mp;
        int l = 0, ans = 0, mx = 0;
        for(int r = 0; r < n ; r++){
            mp[s[r]]++;
            mx = max(mx,mp[s[r]]);
            while( r - l + 1 - mx > k){
                mp[s[l++]]--;
            }
            ans = max(ans , r - l + 1);
        }
        return ans;
    }
};