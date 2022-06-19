class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int n=v.size(),m=v[0].size(),i=0,j=m-1;
        while(i<n&&j>=0&&v[i][j]!=target){
            if(v[i][j]<target){
                if(j!=m-1)return 0;
                else i++;
            }
            else if(v[i][j]>target)j--;
        }
        return i<n&&j>=0&&v[i][j]==target;
    }
};