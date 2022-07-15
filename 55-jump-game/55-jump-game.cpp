class Solution {
public:
    bool canJump(vector<int>&v) {
        int n=v.size(),mx=0;
        for(int i=0;i<n-1;i++){
            mx=max(mx,i+v[i]);
            if(mx==i)return 0;
        }
        return mx>=n-1;
    }
};