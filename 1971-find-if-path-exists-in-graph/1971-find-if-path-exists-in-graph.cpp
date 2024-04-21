
const int N=2e5+5;
class Solution {
public:
    bitset<N>vis;
    vector<int>e[N];
    void dfs(int i){
        vis[i]=1;
        for(auto&it:e[i]){
            if(!vis[it]){
                dfs(it);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(auto it:edges){
            e[it[0]].push_back(it[1]);
            e[it[1]].push_back(it[0]);
      } 
       dfs(source);
       return vis[destination];
    }
};