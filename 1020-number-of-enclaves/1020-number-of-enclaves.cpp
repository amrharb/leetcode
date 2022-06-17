class Solution {
public:
    int cnt=0;
    void dfs(int i,int j,vector<vector<int>>&image){
        int n=image.size(),m=image[0].size();
        cnt--;
        image[i][j]=0;
        if(i-1>=0&&image[i-1][j])dfs(i-1,j,image);
        if(i+1<n&&image[i+1][j])dfs(i+1,j,image);
        if(j-1>=0&&image[i][j-1])dfs(i,j-1,image);
        if(j+1<m&&image[i][j+1])dfs(i,j+1,image);
    }
    int numEnclaves(vector<vector<int>>& image) {
        int n=image.size(),m=image[0].size();
        cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt+=image[i][j];
            }
        }
        for(int i=0;i<n;i++){
            if(image[i][0])dfs(i,0,image);
            if(image[i][m-1])dfs(i,m-1,image);
        }
        for(int j=0;j<m;j++){
            if(image[0][j])dfs(0,j,image);
            if(image[n-1][j])dfs(n-1,j,image);
        }
        return cnt;
    }
};