class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int n=v.size(),mx=1,num=0;
        vector<pair<int,int>>ans(n,make_pair(1,1));
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i]>v[j]&&ans[j].first+1>ans[i].first){
                    ans[i].first=ans[j].first+1;
                    ans[i].second=ans[j].second;
                }
                else if(v[i]>v[j]&&ans[j].first+1==ans[i].first){
                    ans[i].second+=ans[j].second;
                }
            }
            mx=max(mx,ans[i].first);
        }
        for(int i=0;i<n;i++){
            if(ans[i].first==mx)num+=ans[i].second;
        }
        return num;
    }
};