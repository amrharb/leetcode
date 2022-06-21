class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        map<int,map<int,int>>mp;
        int i=0,j=0,n=mat.size(),sum=0;
        while(i<n&&j<n){
            mp[i][j]=1;
            sum+=mat[i++][j++];
        }
        i=0,j=n-1;
        while(i<n&&j>=0){
            if(mp[i][j]){i++,j--;continue;}
            sum+=mat[i++][j--];
        }
        return sum;
    }
};