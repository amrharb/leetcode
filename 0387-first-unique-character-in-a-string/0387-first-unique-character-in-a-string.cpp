class Solution {
public:
    int mp[26];
    int firstUniqChar(string s) {
        for(auto it:s)mp[it-'a']++;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]-'a']==1)return i;
        }
        return -1;
    }
};