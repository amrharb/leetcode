class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>v=arr;
        v.push_back(10000);
        int n=v.size(),l=0,r=n,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(v[mid]-(mid+1)>=k)r=mid-1;
            else l=mid+1;
        }
        return v[l]-(v[l]-(l+1)-k+1);
    }
};