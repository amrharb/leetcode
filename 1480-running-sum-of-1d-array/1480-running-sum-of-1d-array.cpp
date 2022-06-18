class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>pref;
        pref=nums;
        for(int i=1;i<nums.size();i++)pref[i]+=pref[i-1];
        return pref;
    }
};