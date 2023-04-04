class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size(),mx=v.back();
        vector<int>mxElement(n);
        for(int i=n-2;i>=0;i--){
            mxElement[i]=mx;
            mx=max(mx,v[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,mxElement[i]-v[i]);
        }
        return ans;
    }
};