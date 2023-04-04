class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size(),mn=v[0],ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,v[i]-mn);
            mn=min(mn,v[i]);
        }
        return ans;
    }
};