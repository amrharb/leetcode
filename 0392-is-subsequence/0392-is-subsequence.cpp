class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),i=0;
        for(auto it:t){
            if(it==s[i])i++;
            if(i==n)return true;
        }
        return i==n;
    }
};