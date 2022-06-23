class Solution {
public:
    vector<int> res;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        if(graph.size()==0) return {};
        int n = graph.size();
        vector<int> dp(n, -1);
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++)
            if(dp[i]==-1)
                dfs(graph, visited, dp, i);
        for(int i = 0; i < n; i++)
        {
            if(dp[i]==0)
                res.push_back(i);
        }
        return res;
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& dp, int i)
    {
        if(dp[i]==1)
            return true;
        else if(dp[i]==0)
            return false;
        if(visited[i]==1)
        {
            dp[i] = 1;
            return true;
        }
        visited[i] = 1;
        for(auto j:graph[i])
            if(dfs(graph, visited, dp, j))
            {
                dp[i] = 1;
                visited[i] = 0;
                return true;
            }
        visited[i] = 0;
        dp[i] = 0;
        return false;
    }
};