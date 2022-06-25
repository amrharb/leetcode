class Solution {
public:
    int n;
    vector<int>v;
    bool vis[50005];
    bool dfs(int i){
        if(i<0||i>=n||vis[i])return 0;
        if(!v[i])return 1;
        vis[i]=1;
        return dfs(i-v[i])||dfs(i+v[i]);
    }
    bool canReach(vector<int>& arr, int start) {
        n=arr.size();
        v=arr;
        return dfs(start);
    }
};