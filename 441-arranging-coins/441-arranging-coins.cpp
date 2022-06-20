class Solution {
public:
    int arrangeCoins(int n) {
        int l=0,r=n,mid;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid*1LL*(mid+1)/2<=n)l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};