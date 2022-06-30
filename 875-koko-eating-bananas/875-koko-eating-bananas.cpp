class Solution {
public:
    vector<int>v;
    long long mx;
    bool check(long long k){
        long long cnt=0;
        for(auto&it:v)cnt+=(it+k-1)/k;
        return cnt<=mx;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        mx=h,v=piles;
        long long l=1,r=1e9;
        while(l<=r){
            long long mid=l+r>>1;
            if(check(mid))r=mid-1;
            else l=mid+1;
        }
        return r+1;
    }
};