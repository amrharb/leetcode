class Solution {
public:
    int x,y,dp[55][55][55],mod=1e9+7;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool valid(int i,int j){
        return i>=0&&j>=0&&i<x&&j<y;
    }
    int solve(int i,int j,int k){
        if(!valid(i,j))return 1;
        if(!k)return 0;
        int &ret=dp[i][j][k];
        if(~ret)return ret;
        ret=0;
        for(int l=0;l<4;l++){
            int nx=i+dx[l],ny=j+dy[l];
            ret+=solve(nx,ny,k-1);
            ret%=mod;
        }
        return ret;
    }
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        x=n,y=m;
        memset(dp,-1,sizeof dp);
        return solve(startRow,startColumn,maxMove);
    }
};