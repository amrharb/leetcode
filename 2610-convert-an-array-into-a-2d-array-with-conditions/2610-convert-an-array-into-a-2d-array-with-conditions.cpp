class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>freq;
        int mx=0;
        for(auto&it:nums)
            mx=max(mx,++freq[it]);
        vector<vector<int>>ans(mx);
        freq.clear();
        for(auto&it:nums)
            ans[freq[it]++].push_back(it);
        return ans;
    }
};