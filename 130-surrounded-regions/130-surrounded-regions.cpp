class Solution {
public:
    bool vis[205][205];
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int n,m;
    bool valid(int i,int j){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void dfs(vector<vector<char>>&s,int i,int j){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k],y=j+dy[k];
            if(valid(x,y)&&!vis[x][y]&&s[x][y]=='O')dfs(s,x,y);
        }
    }
    void solve(vector<vector<char>>& s) {
        n=s.size(),m=s[0].size();
        for(int i=0;i<n;i++){
            if(s[i][0]=='O'&&!vis[i][0])dfs(s,i,0);
            if(s[i][m-1]=='O'&&!vis[i][m-1])dfs(s,i,m-1);
        }
        for(int j=0;j<m;j++){
            if(s[0][j]=='O'&&!vis[0][j])dfs(s,0,j);
            if(s[n-1][j]=='O'&&!vis[n-1][j])dfs(s,n-1,j);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j])s[i][j]='X';
            }
        }
    }
};