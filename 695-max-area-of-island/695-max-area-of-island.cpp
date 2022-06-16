class Solution {
public:
    int cnt=0;
    void dfs(int i,int j,vector<vector<int>>&image){
        int n=image.size(),m=image[0].size();
        image[i][j]=0;
        if(i>=1&&image[i-1][j])dfs(i-1,j,image),cnt++;
        if(i+1<n&&image[i+1][j])dfs(i+1,j,image),cnt++;
        if(j>=1&&image[i][j-1])dfs(i,j-1,image),cnt++;
        if(j+1<m&&image[i][j+1])dfs(i,j+1,image),cnt++;
    }
    int maxAreaOfIsland(vector<vector<int>>& image) {
        int n=image.size(),m=image[0].size(),mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(image[i][j]){
                    cnt=1;
                    dfs(i,j,image);
                    mx=max(mx,cnt);
                }
            }
        }
        return mx;
    }
};