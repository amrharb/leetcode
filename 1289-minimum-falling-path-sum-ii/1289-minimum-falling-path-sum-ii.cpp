class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<int>dp(m);
        multiset<int>st;
        for(int j=0;j<m;j++)
            dp[j]=v[0][j],st.insert(dp[j]);
        for(int i=1;i<n;i++)
        {
            multiset<int>nw;
            for(int j=0;j<m;j++)
            {
                int last=dp[j];
                st.erase(st.find(dp[j]));
                dp[j]=v[i][j]+*st.begin();
                st.insert(last);
                nw.insert(dp[j]);
            }
            st=nw;
        }
        return *min_element(dp.begin(),dp.end());
    }
};