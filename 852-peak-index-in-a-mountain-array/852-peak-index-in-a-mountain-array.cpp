class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int n=v.size();
        int l=1,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            bool flag1=1,flag2=1;
            for(int i=0;i<mid;i++)flag1&=v[i]<v[i+1];
            for(int i=n-1;i>mid;i--)flag2&=v[i]<v[i-1];
            if(flag1&&flag2)return mid;
            else if(flag1&&!flag2)l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};