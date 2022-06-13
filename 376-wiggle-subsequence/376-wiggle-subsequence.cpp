class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int n=v.size();
        vector<int>ans(2,1);
        for(int i=1;i<n;i++){
            if(v[i]>v[i-1])ans[0]=ans[1]+1;
            else if(v[i]<v[i-1])ans[1]=ans[0]+1;
        }
        return max(ans[0],ans[1]);
    }
};