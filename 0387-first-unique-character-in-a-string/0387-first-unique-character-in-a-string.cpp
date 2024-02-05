class Solution {
public:
    int mp[26];
    int firstUniqChar(string s) {
        for(auto it:s)mp[it-'a']++;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mp[s[i]-'a']==1)return i;
        }
        return -1;
    }
};