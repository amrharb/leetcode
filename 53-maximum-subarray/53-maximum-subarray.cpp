class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int sum=0,mx=-1e9,n=v.size();
        for(int i=0;i<n;i++){
            sum+=v[i];
            mx=max(mx,sum);
            if(sum<0)sum=0;
        }
        return mx;
    }
};