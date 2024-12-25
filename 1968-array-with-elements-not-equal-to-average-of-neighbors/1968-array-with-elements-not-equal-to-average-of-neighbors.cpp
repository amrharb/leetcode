class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=0;i<(n+1)/2;i++){
            ans.push_back(nums[i]);
            if(i+(n+1)/2<n)
                ans.push_back(nums[i+(n+1)/2]);
        }
        return ans;
    }
};