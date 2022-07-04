class Solution {
public:
    int candy(vector<int>& rate) {
        int n=rate.size();
        vector<int>a(n,1),b(n,1),ans(n);
        for(int i=1;i<n;i++){
            if(rate[i]>rate[i-1])a[i]=a[i-1]+1;
        }
        ans[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            if(rate[i]>rate[i+1])b[i]=max(b[i],b[i+1]+1);
            ans[i]=max(a[i],b[i]);
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};