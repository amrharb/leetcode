class Solution {
public:
    vector<int> searchRange(vector<int>& v, int target) {
        int n=v.size(),l=0,r=n-1,mid,ans=0;
        while(l<=r){
            mid=(l+r)/2;
            if(v[mid]>=target){
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=l;
        if(l==n||v[ans]!=target)return {-1,-1};
        l=0,r=n-1;
        while(l<=r){
            mid=(l+r)/2;
            if(v[mid]>target){
                r=mid-1;
            }
            else l=mid+1;
        }
        return {ans,r};
    }
};