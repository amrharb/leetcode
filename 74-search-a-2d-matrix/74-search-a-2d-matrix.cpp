class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int n=v.size(),m=v[0].size();
        for(int i=0;i<n;i++){
            if(v[i][m-1]<target)continue;
            int l=0,r=m-1;
            while(l<=r){
                int mid=l+r >> 1;
                if(v[i][mid]==target)return 1;
                else if(v[i][mid]>target)r=mid-1;
                else l=mid+1;
            }
        }
        return 0;
    }
};