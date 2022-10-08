const int N=205;
class Solution
{
public:
    int dp[N][N],sum[N][N],n,m;
    bool check(vector<vector<int>>&v,int k){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=1e9;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i&&!j)dp[i][j]=v[i][j]+k;
                else if(!i)dp[i][j]=v[i][j]+dp[i][j-1];
                else if(!j)dp[i][j]=v[i][j]+dp[i-1][j];
                else dp[i][j]=v[i][j]+max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j]<=0)dp[i][j]=-1e9;
            }
        }
        return dp[n-1][m-1]>0;
    }
    int calculateMinimumHP(vector<vector<int>>& v)
    {
        n=v.size(),m=v[0].size();
        int l=1,r=2e5;
        while(l<=r){
            int mid=l+r>>1;
            if(check(v,mid))r=mid-1;
            else l=mid+1;
        }
        return r+1;
    }
};
