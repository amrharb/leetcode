const int N=30;
class Solution {
public:
    vector<int>adj[N];
    int cost[N],response[N];
    bool vis[N];
    int dfs(int i){
        vis[i]=1;
        cost[i]=i;
        for(auto&it:adj[i]){
            if(!vis[it])dfs(it);
            cost[i]=min(cost[i],cost[it]);
        }
        return cost[i];
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        for(int i=0;i<n;i++){
            adj[s1[i]-'a'].push_back(s2[i]-'a');
            adj[s2[i]-'a'].push_back(s1[i]-'a');
        }
        for(int i=0;i<26;i++){
           memset(vis,0,sizeof vis);
           dfs(i);
           response[i]=cost[i];
        }
        int m=baseStr.size();
        string ans;
        for(int i=0;i<m;i++){
            ans+=(response[baseStr[i]-'a']+'a');
        }
        return ans;
    }
};