class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int l=0,r=0,n=v.size(),mn=1e9,sum=0;
        while(l<n){
            while(r<n&&sum<target){
                sum+=v[r++];
            }
            if(sum>=target)mn=min(mn,r-l);
            sum-=v[l++];
        }
        return (mn>n ? 0:mn);
    }
};