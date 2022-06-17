class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        int n=v.size(),mx=0;
        sort(v.begin(),v.end());
        for(int i=3;i<=n;i++){
        if(v[i-2]+v[i-3]>v[i-1])mx=max(mx,v[i-2]+v[i-3]+v[i-1]);}
        return mx;
    }
};