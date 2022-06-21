class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i=0,j=0,n=mat.size(),sum=0;
        while(i<n&&j<n){
            sum+=mat[i++][j++];
        }
        i=0,j=n-1;
        while(i<n&&j>=0){
            sum+=mat[i++][j--];
        }
        if(n&1)sum-=mat[n/2][n/2];
        return sum;
    }
};