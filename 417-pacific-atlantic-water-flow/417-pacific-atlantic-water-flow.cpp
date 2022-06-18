class Solution {
public:
    int n,m;
    vector<vector<bool>>vis;
    vector<vector<int>>heights;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool valid(int i,int j){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    void dfs(int i,int j){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nx=i+dx[k],ny=j+dy[k];
            if(valid(nx,ny)&&!vis[nx][ny]&&heights[nx][ny]>=heights[i][j])dfs(nx,ny);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
        heights=height;
        n=heights.size(),m=heights[0].size();
        vector<vector<bool>>pac(n,vector<bool>(m,0)),atl=pac;
        vector<vector<int>>cnt;
        for(int i=0;i<n;i++){
            vis=pac;
            dfs(i,0);
            pac=vis;
            vis=atl;
            dfs(i,m-1);
            atl=vis;
        }
        for(int i=0;i<m;i++){
            vis=pac;
            dfs(0,i);
            pac=vis;
            vis=atl;
            dfs(n-1,i);
            atl=vis;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(pac[i][j]&&atl[i][j])cnt.push_back({i,j});
            }
        }
        return cnt;
    }
};