class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        for(auto&it:nums){
            auto el=lower_bound(ans.begin(),ans.end(),it);
            if(el!=ans.end())*el=it;
            else ans.push_back(it);
        }
        return ans.size();
    }
};