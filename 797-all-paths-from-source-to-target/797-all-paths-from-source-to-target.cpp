class Solution {
public:
    int n;
    vector<vector<int>>adj,ans;
    void dfs(int i,int par,vector<int>v){
        if(i==n-1){
            ans.push_back(v);
            return;
        }
        for(auto&it:adj[i]){
            if(it!=par){
                v.push_back(it);
                dfs(it,i,v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        adj=graph;
        dfs(0,0,{0});
        return ans;
    }
};