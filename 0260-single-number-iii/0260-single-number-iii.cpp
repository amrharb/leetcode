class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,short>mp;
        vector<int> sol;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto&it:mp){
            if(it.second==1)sol.push_back(it.first);
        }
        return sol;
    }
};