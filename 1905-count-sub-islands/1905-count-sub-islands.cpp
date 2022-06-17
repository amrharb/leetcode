class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>&image1,vector<vector<int>>&image2){
        int n=image1.size(),m=image1[0].size();
        image2[i][j]=0;
        int ret=1;
        if(!image1[i][j])ret=0;
        if(i-1>=0&&image2[i-1][j])ret&=dfs(i-1,j,image1,image2);
        if(i+1<n&&image2[i+1][j])ret&=dfs(i+1,j,image1,image2);
        if(j-1>=0&&image2[i][j-1])ret&=dfs(i,j-1,image1,image2);
        if(j+1<m&&image2[i][j+1])ret&=dfs(i,j+1,image1,image2);
        return ret;
    }
    int countSubIslands(vector<vector<int>>& image1, vector<vector<int>>& image2) {
        int n=image1.size(),m=image1[0].size(),cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(image2[i][j])cnt+=dfs(i,j,image1,image2);
            }
        }
        return cnt;
    }
};