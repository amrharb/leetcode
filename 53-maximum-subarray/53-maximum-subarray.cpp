class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int sum=0,mx=-1e9;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            mx=max(mx,sum);
            if(sum<0)sum=0;
        }
        return mx;
    }
};