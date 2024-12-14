class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        for(auto &it:nums){
            if(it==val){
                it=1e9;
                n--;
            }
        }
        sort(nums.begin(),nums.end());
        return n;
    }
};