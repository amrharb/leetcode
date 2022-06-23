class Solution {
public:
    bool checkIfExist(vector<int>& v) {
        int n=v.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp[v[i]*2])return 1;
            if(v[i]%2==0&&mp[v[i]/2])return 1;
            mp[v[i]]++;
        }
        return 0;
    }
};