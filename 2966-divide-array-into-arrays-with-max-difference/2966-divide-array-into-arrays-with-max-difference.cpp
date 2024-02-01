class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> ans(n/3,{0,0,0});
        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            ans[i/3][0]=nums[i];
            ans[i/3][1]=nums[i + 1];
            ans[i/3][2]=nums[i + 2];
        }
        return ans;
    }
};