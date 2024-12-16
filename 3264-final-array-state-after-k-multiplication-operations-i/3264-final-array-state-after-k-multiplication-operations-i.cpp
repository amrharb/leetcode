class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        for(int i=0;i<k;i++){
            int mn=0;
            for(int j=1;j<n;j++){
                if(nums[j]<nums[mn])
                    mn=j;
            }
            nums[mn]*=multiplier;
        }
        return nums;
    }
};