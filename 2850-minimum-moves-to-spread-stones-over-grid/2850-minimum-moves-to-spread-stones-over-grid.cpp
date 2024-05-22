class Solution {
public:
    int cur[4][4];
    int solve(int i)
    {
        if(i==9)
            return 0;
        int ret=1e9;
        if(cur[i/3][i%3])
            return ret=solve(i+1);
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(cur[j][k]>1)
                {
                    cur[j][k]--;
                    cur[i/3][i%3]=1;
                    ret=min(ret,abs(j-i/3)+abs(k-i%3)+solve(i+1));
                    cur[i/3][i%3]=0;
                    cur[j][k]++;
                }
            }
        }
        return ret;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cur[i][j]=grid[i][j];
            }
        }
        return solve(0);
    }
};