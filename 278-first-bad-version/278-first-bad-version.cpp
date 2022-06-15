// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l=1,r=n,mid,k;
        while(l<=r){
            mid=(l+r)/2;
            if(isBadVersion(mid))r=mid-1;
            else l=mid+1;
        }
        return r+1;
    }
};