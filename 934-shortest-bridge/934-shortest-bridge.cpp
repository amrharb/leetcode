class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        bool flag=false;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    floodfill(grid,i,j,q);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        
        vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        int steps=0; 
        while(!q.empty())
        {
            int q_size = q.size();
            for(int i=0;i<q_size;i++)
            {
                auto [r,c] = q.front();
                q.pop();
                for(auto dir:dirs)
                {
                    int row = r + dir[0];
                    int col = c + dir[1];
                    if(row>=0 && col>=0 && row<grid.size() && col<grid[0].size() && grid[row][col]!=-1)
                    {
                        if(grid[row][col]==1) return steps;
                        q.push({row,col});
                        grid[row][col]=-1;
                    }
                    
                }
            }
            steps++;
        }
        return -1;
    }
    void floodfill(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>> &q)
    {  
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]!=1)
            return;
        grid[i][j]=-1;
        q.push({i,j});
        floodfill(grid,i+1,j,q);
        floodfill(grid,i,j+1,q);
        floodfill(grid,i-1,j,q);
        floodfill(grid,i,j-1,q);
    }
};