class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx=0,n=accounts.size();
        for(int i=0;i<n;i++){
            mx=max(mx,accumulate(accounts[i].begin(),accounts[i].end(),0));
        }
        return mx;
    }
};