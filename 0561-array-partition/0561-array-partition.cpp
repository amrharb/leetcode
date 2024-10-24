class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0,n=nums.size()/2;
        for(int i=0;i<2*n;i+=2){
            sum+=nums[i];
        }
        return sum;
    }
};