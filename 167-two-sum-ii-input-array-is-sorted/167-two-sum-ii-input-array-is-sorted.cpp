class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n=v.size(),l=0,r=n-1;
        while(l<r){
            if(v[l]+v[r]==target)return {l+1,r+1};
            else if(v[l]+v[r]>target)r--;
            else l++;
        }
        return {-1,-1};
    }
};