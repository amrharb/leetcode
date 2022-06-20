class Solution
{
public:
    int n,m;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool valid(int i,int j){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& pos)
    {
        n=maze.size(),m=maze[0].size();
        if(maze[pos[0]][pos[1]]=='+')return -1;
        queue<pair<int,int>>q;
        q.push({pos[0],pos[1]});
        maze[pos[0]][pos[1]]='+';
        int steps=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int nx=x+dx[k],ny=y+dy[k];
                    if(valid(nx,ny)&&maze[nx][ny]=='.')
                    {
                       if((!nx||!ny|nx==n-1|ny==m-1))return steps;
                        maze[nx][ny]='+';
                        q.push({nx,ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};