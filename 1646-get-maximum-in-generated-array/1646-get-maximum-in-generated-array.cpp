class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int>ans(n+2);
        ans[0]=0;
        ans[1]=1;
        for(int i=2;i<=n;i++){
            ans[i]+=ans[i/2];
            if(i&1)ans[i]+=ans[i/2+1];
        }
        return *max_element(ans.begin(),ans.begin()+n+1);
    }
};