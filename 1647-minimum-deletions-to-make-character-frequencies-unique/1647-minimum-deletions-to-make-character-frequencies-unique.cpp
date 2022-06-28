class Solution {
public:
    int minDeletions(string s) {
        int mx=0,cnt=0;
        map<char,int>mp;
        map<int,bool>mk;
        set<int>st;
        for(auto&it:s)mp[it]++;
        for(auto&it:mp){
            while(mk[it.second]){
                it.second--;
                cnt++;
            }
            if(it.second)mk[it.second]=1;
        }
        return cnt;
    }
};