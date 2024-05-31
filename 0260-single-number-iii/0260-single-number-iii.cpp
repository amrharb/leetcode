class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>sol;
        int n=nums.size();
        for(int i=0;i<n;i++)
            if((i+1==n||nums[i]!=nums[i+1])&&(!i||nums[i-1]!=nums[i]))
               sol.push_back(nums[i]);
        return sol;
    }
};