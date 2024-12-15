class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>pref(n);
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            pref[i]=max(0,prices[i]-mn);
            if(i)pref[i]=max(pref[i],pref[i-1]);
            mn=min(mn,prices[i]);
        }
        int mx=0,ans=0;
        for(int i=n-1;i>=0;i--){
            mx=max(mx,prices[i]);
            ans=max(ans,mx-prices[i]+(i ? pref[i-1]:0));
        }
        return ans;
    }
};