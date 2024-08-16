class Solution {
public:
    int maxDistance(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>mx(n);
        mx[n-1]=v.back().back();
        for(int i=n-2;i>=0;i--){
            mx[i]=max(mx[i+1],v[i].back());
        }
        int ans=0,MAX=-1e9;
        for(int i=0;i<n;i++){
            ans=max(ans,MAX-v[i][0]);
            if(i!=n-1)
                ans=max(ans,mx[i+1]-v[i][0]);
            MAX=max(MAX,v[i].back());
        }
        return ans;
    }
};