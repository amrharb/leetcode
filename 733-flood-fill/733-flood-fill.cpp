class Solution {
public:
    int n,m;
    void dfs(int i,int j,int color,int newColor,vector<vector<int>>&image){
            if(image[i][j]==color){
                image[i][j]=newColor;
                if(i>=1)dfs(i-1,j,color,newColor,image);
                if(i+1<n)dfs(i+1,j,color,newColor,image);
                if(j>=1)dfs(i,j-1,color,newColor,image);
                if(j+1<m)dfs(i,j+1,color,newColor,image);
            }
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n=image.size(),m=image[0].size();
        if(image[sr][sc]==newColor)return image;
        dfs(sr,sc,image[sr][sc],newColor,image);
        return image;
    }
};