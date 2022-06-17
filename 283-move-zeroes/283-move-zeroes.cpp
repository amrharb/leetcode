class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        vector<int>v(nums.size(),0);
        for(auto it:nums){
            if(it!=0)v[i++]=it;
        }
        nums=v;
    }
};