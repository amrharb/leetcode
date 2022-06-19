class Solution {
public:
    int dx[8]={0,0,1,1,1,-1,-1,-1};
    int dy[8]={1,-1,0,1,-1,0,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        q.push({0,0});
        if(grid[0][0])return -1;
        int steps=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1&&y==n-1)return steps;
                for(int k=0;k<8;k++){
                    int nx=x+dx[k],ny=y+dy[k];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&!grid[nx][ny]){
                        q.push({nx,ny});
                        grid[nx][ny]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};