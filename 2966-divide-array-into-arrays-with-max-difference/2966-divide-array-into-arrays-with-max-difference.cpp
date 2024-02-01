class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(auto&it:nums)
        {
            if(!ans.empty()&&ans.back().size()<3)
            {
                if(it-ans.back()[0]>k)
                    return {};
                ans.back().push_back(it);
            }
            else
            {
                ans.push_back({it});
            }
        }
        return ans;
    }
};