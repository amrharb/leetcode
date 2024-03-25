const int N=1e5+5;
bitset<N>vis;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vis.reset();
        vector<int>v;
        for(auto&it:nums)
        {
            if(vis[it])
                v.push_back(it);
            vis[it]=1;
        }
        return v;
    }
};