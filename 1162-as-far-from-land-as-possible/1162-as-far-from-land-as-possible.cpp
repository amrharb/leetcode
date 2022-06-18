class Solution
{
public:
    int dx[4]= {0,0,1,-1};
    int dy[4]= {1,-1,0,0};
    int maxDistance(vector<vector<int>>& grid)
    {
        int n=grid.size();
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j])
                {
                    q.push({i,j});
                }
            }
        }
        if(q.size()==n*n||q.empty())return -1;
        int steps=-1;
        while(!q.empty())
        {
            steps++;
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int x=p.first+dx[k],y=p.second+dy[k];
                    if(x>=0&&x<n&&y>=0&&y<n&&!grid[x][y])
                    {
                        q.push({x,y});
                        grid[x][y]=1;
                    }
                }
            }
        }
        return steps;
    }
};