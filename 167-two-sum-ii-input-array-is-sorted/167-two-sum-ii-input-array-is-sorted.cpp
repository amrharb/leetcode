class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n= v.size();
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1,mid;
            while(l<=r){
                mid=(l+r)/2;
                if(v[mid]==target-v[i])return {i+1,mid+1};
                else if(v[mid]>target-v[i])r=mid-1;
                else l=mid+1;
            }
        }
        return {-1,-1};
    }
};