class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        multiset<int>st;
        for(int j=0;j<m;j++)
            dp[0][j]=v[0][j],st.insert(dp[0][j]);
        for(int i=1;i<n;i++)
        {
            multiset<int>nw;
            for(int j=0;j<m;j++)
            {
                st.erase(st.find(dp[i-1][j]));
                dp[i][j]=min(dp[i][j],v[i][j]+*st.begin());
                st.insert(dp[i-1][j]);
                nw.insert(dp[i][j]);
            }
            st=nw;
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};