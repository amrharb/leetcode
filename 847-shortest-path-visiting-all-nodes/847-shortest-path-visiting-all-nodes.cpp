class Solution {
public:
    bool vis[12][1<<12];
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size(),steps=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)q.push({i,1<<i});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto cur=q.front();q.pop();
                if(cur.second==(1<<n)-1)return steps;
                for(auto&it:graph[cur.first]){
                    if(vis[it][cur.second|(1<<it)]==1)continue;
                    q.push({it,cur.second|(1<<it)});
                    vis[it][cur.second|(1<<it)]=1;
                }
            }
            steps++;
        }
        return -1;
    }
};