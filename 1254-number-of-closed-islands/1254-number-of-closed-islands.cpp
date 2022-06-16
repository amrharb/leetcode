class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&image){
        int n=image.size(),m=image[0].size();
        if(!(i>=0&&j>=0&&i<n&&j<m))return 0;
        if(image[i][j])return 1;
        image[i][j]=2;
        int up=dfs(i-1,j,image);
        int down=dfs(i+1,j,image);
        int left=dfs(i,j-1,image);
        int right=dfs(i,j+1,image);
        return up&&down&&left&&right;
    }
    int closedIsland(vector<vector<int>>& image) {
        int n=image.size(),m=image[0].size(),cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!image[i][j])cnt+=dfs(i,j,image);
            }
        }
        return cnt;
    }
};