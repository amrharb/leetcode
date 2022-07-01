class Solution {
public:
    int findMin(vector<int>& v) {
        int n=v.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[v[i]];
        return (*mp.begin()).first;
    }
};