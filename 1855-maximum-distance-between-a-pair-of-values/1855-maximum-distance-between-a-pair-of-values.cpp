class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size(),mx=0;
        for(int i=0;i<n;i++){
            int l=0,r=m-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(b[mid]>=a[i])l=mid+1;
                else r=mid-1;
            }
            mx=max(mx,l-i-1);
        }
        return mx;
    }
};