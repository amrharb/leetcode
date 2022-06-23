class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=0;
                }
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]==1){
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
               }
            }
            if(q.size())steps++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])return -1;
            }
        }
        return steps;
    }
};