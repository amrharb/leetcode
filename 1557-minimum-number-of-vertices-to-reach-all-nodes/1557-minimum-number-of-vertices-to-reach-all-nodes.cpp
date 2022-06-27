class Solution {
public:
    int vis[100005];
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        for(auto&it:edges)vis[it[1]]++;
        for(int i=0;i<n;i++){
            if(!vis[i])ans.push_back(i);
        }
        return ans;
    }
};