class Solution {
public:
    int specialArray(vector<int>& v) {
        int n= v.size();
        sort(v.begin(),v.end());
        int l=0,r=1000;
        while(l<=r){
            int mid=(l+r)/2;
            int k=lower_bound(v.begin(),v.end(),mid)-v.begin();
            if(n-k==mid)return mid;
            else if(n-k>mid)l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};