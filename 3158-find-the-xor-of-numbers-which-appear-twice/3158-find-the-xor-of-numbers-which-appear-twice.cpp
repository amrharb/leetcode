class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        bitset<51>vis;
        for(auto&it:nums)
            vis[it].flip();
        short xr=0;
        for(auto&it:nums)
            if(!vis[it])
                xr^=it,vis[it].flip();
        return xr;
    }
};