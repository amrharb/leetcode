class Solution {
public:
    int sum(int n)
    {
        return n*(n+1)/2;
    }
    int pivotInteger(int n) {
        int l=1,r=n;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(sum(mid)==sum(n)-sum(mid-1))
                return mid;
            if(sum(mid)>sum(n)-sum(mid))
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
};