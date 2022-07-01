class Solution {
public:
    int findMin(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+r>>1;
            if(v[mid]>=v[0])l=mid+1;
            else r=mid-1;
        }
        return v[(r+1)%n];
    }
};