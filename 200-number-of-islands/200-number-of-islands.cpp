class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&image){
        int n=image.size(),m=image[0].size();
            if(image[i][j]=='1'){
                image[i][j]='0';
                if(i>=1)dfs(i-1,j,image);
                if(i+1<n)dfs(i+1,j,image);
                if(j>=1)dfs(i,j-1,image);
                if(j+1<m)dfs(i,j+1,image);
            }
    }
    int numIslands(vector<vector<char>>& image) {
        int n=image.size(),m=image[0].size(),cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(image[i][j]=='1')dfs(i,j,image),cnt++;
            }
        }
        return cnt;
    }
};