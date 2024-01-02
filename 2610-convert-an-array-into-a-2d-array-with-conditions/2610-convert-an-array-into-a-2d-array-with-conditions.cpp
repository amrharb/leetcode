int freq[201];
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        memset(freq,0,sizeof freq);
        int mx=0;
        for(auto&it:nums)
            mx=max(mx,++freq[it]);
        vector<vector<int>>ans(mx);
        memset(freq,0,sizeof freq);
        for(auto&it:nums)
            ans[freq[it]++].push_back(it);
        return ans;
    }
};