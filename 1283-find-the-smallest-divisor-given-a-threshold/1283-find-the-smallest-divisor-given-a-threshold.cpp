class Solution {
public:
    int check(vector<int>v,int k){
        int cnt=0;
        for(auto&it:v)cnt+=(it+k-1)/k;
        return cnt;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=(l+r)/2;
            int ans=check(nums,mid);
            if(ans<=threshold)r=mid-1;
            else l=mid+1;
        }
        return r+1;
    }
};