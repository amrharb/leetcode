class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,int>adj;
        map<int,map<int,int>>mp;
        for(auto&it:roads){
            adj[it[0]]++;
            adj[it[1]]++;
            mp[it[0]][it[1]]=mp[it[1]][it[0]]=1;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cnt=max(cnt,adj[i]+adj[j]-mp[i][j]);
            }
        }
        return cnt;
    }
};