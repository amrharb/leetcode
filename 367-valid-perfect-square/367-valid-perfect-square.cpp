class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l=1,r=1e6;
        while(l<=r){
            long long mid=(l+r)/2;
            if(mid*mid==num)return 1;
            else if(mid*mid>num)r=mid-1;
            else l=mid+1;
        }
        return 0;
    }
};