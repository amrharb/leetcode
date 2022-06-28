class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mp;
        int sol;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto&it:mp){
            if(it.second==1)sol=it.first;
        }
        return sol;
    }
};