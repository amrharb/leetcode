class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size(),mn=v[0],ans=0;
        for(int i=0;i<n;i++){
            if(v[i]-mn>ans)
                ans=v[i]-mn;
            if(v[i]<mn)
                mn=v[i];
        }
        return ans;
    }
};