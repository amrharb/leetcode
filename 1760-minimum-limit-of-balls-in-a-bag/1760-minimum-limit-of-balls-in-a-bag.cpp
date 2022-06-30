class Solution {
public:
    int mx;
    vector<int>v;
    bool check(int k){
        int cnt=0;
        for(auto&it:v)cnt+=it/k-!(it%k);
        return cnt<=mx;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        mx=maxOperations,v=nums;
        int l=1,r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid))r=mid-1;
            else l=mid+1;
        }
        return r+1;
    }
};