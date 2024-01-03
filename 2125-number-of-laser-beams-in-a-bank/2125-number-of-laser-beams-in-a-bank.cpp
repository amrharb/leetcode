class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size(),m=bank[0].size(),ans=0,last=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
                cnt+=(bank[i][j]=='1');
            if(cnt)
                ans+=cnt*last,last=cnt;
        }
        return ans;
    }
};